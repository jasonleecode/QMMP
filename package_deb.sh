#!/usr/bin/env bash
set -euo pipefail
root=$(cd "$(dirname "$0")" && pwd)
build=$(realpath "${BUILD_DIR:-$root/build-classic}")
dist="$build/dist"
mkdir -p "$dist"
work=$(mktemp -d)
trap 'rm -rf "$work"' EXIT
cd "$work"
pkg="$work/debian/qmmp"
mkdir -p "$pkg/DEBIAN"
DESTDIR="$pkg" cmake --install "$build" --prefix /usr >/dev/null
usr="$pkg/usr"
lib="$usr/lib"
plugins="$lib/qmmp-2.3"
for module in Input/libmpeg Input/libffmpeg Ui/libclassic; do
    [[ -f "$plugins/$module.so" ]] || { echo "缺少必需插件 $module" >&2; exit 1; }
done
qt=${QT_PATH:-$(sed -n 's|^Qt6_DIR:PATH=\(.*\)/lib/cmake/Qt6$|\1|p' "$build/CMakeCache.txt")}
[[ -x "$qt/bin/qtpaths" ]] || { echo "请用 QT_PATH 指定构建使用的 Qt SDK" >&2; exit 1; }
qtlib=$("$qt/bin/qtpaths" --query QT_INSTALL_LIBS)
qtplugins=$("$qt/bin/qtpaths" --query QT_INSTALL_PLUGINS)
bundle="$lib/qmmp/qt6"
bindir="$lib/qmmp/bin"
mkdir -p "$bundle" "$bindir"
mv "$usr/bin/qmmp" "$bindir/"
ln -s ../lib/qmmp/bin/qmmp "$usr/bin/qmmp"
echo -e '[Paths]\nPrefix=../qt6\nPlugins=plugins' > "$bindir/qt.conf"
qt_translations=$("$qt/bin/qtpaths" --query QT_INSTALL_TRANSLATIONS)
if [[ -f "$qt_translations/qtbase_zh_CN.qm" ]]; then
    install -Dm644 "$qt_translations/qtbase_zh_CN.qm" "$bundle/translations/qtbase_zh_CN.qm"
fi

# Keep Qt's platform, image, icon and audio plugins together with their private libraries.
install_qt_plugin() {
    local group=$1
    shift
    mkdir -p "$bundle/plugins/$group"
    for file in "$@"; do
        cp "$qtplugins/$group/$file.so" "$bundle/plugins/$group/"
    done
}
install_qt_plugin platforms libqxcb libqoffscreen
install_qt_plugin sqldrivers libqsqlite
for group in xcbglintegrations imageformats iconengines; do
    mkdir -p "$bundle/plugins/$group"
    cp "$qtplugins/$group/"*.so "$bundle/plugins/$group/"
done
if [[ -e "$plugins/Output/libqtmultimedia.so" ]]; then
    install_qt_plugin multimedia libgstreamermediaplugin
fi
if [[ -e "$qtplugins/platforms/libqwayland-generic.so" ]] &&
   ! ldd -r "$qtplugins/platforms/libqwayland-generic.so" 2>&1 | grep "undefined symbol" >/dev/null; then
    install_qt_plugin platforms libqwayland-generic
    for group in wayland-shell-integration wayland-decoration-client; do
        mkdir -p "$bundle/plugins/$group"
        cp "$qtplugins/$group/"*.so "$bundle/plugins/$group/"
    done
fi

# ldd resolves the transitive Qt SDK dependencies (including its ICU build).
mapfile -d '' modules < <(find "$usr" -type f \( -name '*.so*' -o -name qmmp \) -print0)
export LD_LIBRARY_PATH="$lib:$qtlib"
ldd "${modules[@]}" > "$work/linked"
if grep -F 'not found' "$work/linked"; then exit 1; fi
while read -r soname path; do
    cp -L "$path" "$bundle/$soname"
done < <(awk -v prefix="$qtlib/" '$2=="=>" && index($3,prefix)==1 {print $1, $3}' "$work/linked" | sort -u)

mapfile -d '' binaries < <(find "$usr" -type f \( -name '*.so*' -o -name qmmp \) -print0)
# Older patchelf versions can damage the ELF notes Qt uses for plugin discovery.
# Keep plugins byte-for-byte intact and supply a transitive lookup path on the host.
patchelf --force-rpath --set-rpath '$ORIGIN/../qt6:$ORIGIN/../..' "$bindir/qmmp"
for library in "$lib"/libqmmp*.so.2; do
    patchelf --set-rpath '$ORIGIN/qmmp/qt6:$ORIGIN' "$(realpath "$library")"
done
unset LD_LIBRARY_PATH
env -u QT_PLUGIN_PATH -u QT_QPA_PLATFORM_PLUGIN_PATH QT_QPA_PLATFORM=offscreen \
    XDG_CONFIG_HOME="$work/config" XDG_DATA_HOME="$work/data" XDG_CACHE_HOME="$work/cache" \
    QMMP_PLUGINS="$plugins" "$usr/bin/qmmp" --version
# Debian supplies the external audio codecs and desktop libraries. Private SONAMEs
# belong to this package, so dpkg-shlibdeps should omit them from Depends.
cat > debian/control <<'CONTROL'
Source: qmmp
Section: sound
Priority: optional
Maintainer: Ilya Kotov <forkotov02@ya.ru>

Package: qmmp
Architecture: any
Description: Qt music player with a compact Chinese interface
CONTROL
for library in "$bundle/"*.so.* "$lib"/libqmmp*.so.2; do
    name=$(patchelf --print-soname "$library")
    [[ "$name" == *.so.* ]] && echo "${name%.so.*} ${name##*.so.} qmmp"
done > debian/shlibs.local
depends=$(dpkg-shlibdeps -O -xqmmp "-l$lib" "-l$bundle" "${binaries[@]}" | sed -n 's/^shlibs:Depends=//p')
[[ -n "$depends" ]]
version=$(sed -n 's/^Version: //p' "$lib/pkgconfig/qmmp.pc")
version="$version-1"
arch=$(dpkg --print-architecture)
cat > "$pkg/DEBIAN/control" <<CONTROL
Package: qmmp
Version: $version
Section: sound
Priority: optional
Architecture: $arch
Depends: $depends
Maintainer: Ilya Kotov <forkotov02@ya.ru>
Description: Qt music player with a compact Chinese interface and synchronized lyrics
CONTROL
install -Dm644 "$root/src/app/images/scalable/qmmp-classic.svg" "$usr/share/icons/hicolor/scalable/apps/qmmp-classic.svg"
dpkg-deb --root-owner-group --build "$pkg" "$work/player.deb"
mv "$work/player.deb" "$dist/qmmp_${version}_${arch}.deb"
echo "$dist/qmmp_${version}_${arch}.deb"
