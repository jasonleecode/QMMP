#!/bin/bash

# Configuration
PKG_NAME="qmmp"
PKG_VERSION="2.3.1"
PKG_ARCH="amd64"
PKG_DIR="${PKG_NAME}_${PKG_VERSION}_${PKG_ARCH}"
BUILD_DIR="build-linux"
QT_LIB_DIR="/home/lixiang/Qt/6.5.3/gcc_64/lib"

echo "Creating Debian package structure in ${PKG_DIR}..."

# 1. Create directory structure
rm -rf "${PKG_DIR}"
mkdir -p "${PKG_DIR}/DEBIAN"
mkdir -p "${PKG_DIR}/usr/bin"
mkdir -p "${PKG_DIR}/usr/lib"
mkdir -p "${PKG_DIR}/usr/lib/qmmp-2.3"
mkdir -p "${PKG_DIR}/usr/share/applications"
mkdir -p "${PKG_DIR}/usr/share/icons/hicolor"
mkdir -p "${PKG_DIR}/usr/share/metainfo"

# 2. Copy main executable
cp "${BUILD_DIR}/src/app/qmmp" "${PKG_DIR}/usr/bin/"

# 3. Copy shared libraries
cp "${BUILD_DIR}/src/qmmp/libqmmp.so.2.3.1" "${PKG_DIR}/usr/lib/"
ln -sf "libqmmp.so.2.3.1" "${PKG_DIR}/usr/lib/libqmmp.so.2"
ln -sf "libqmmp.so.2.3.1" "${PKG_DIR}/usr/lib/libqmmp.so"

cp "${BUILD_DIR}/src/qmmpui/libqmmpui.so.2.3.1" "${PKG_DIR}/usr/lib/"
ln -sf "libqmmpui.so.2.3.1" "${PKG_DIR}/usr/lib/libqmmpui.so.2"
ln -sf "libqmmpui.so.2.3.1" "${PKG_DIR}/usr/lib/libqmmpui.so"

# 4. Copy and flatten plugins structure
echo "Flattening and copying plugins..."
find "${BUILD_DIR}/src/plugins" -name "*.so" | while read -r plugin_path; do
    plugin_name=$(basename "$plugin_path")
    category_dir=$(basename "$(dirname "$plugin_path")")
    parent_dir=$(basename "$(dirname "$(dirname "$plugin_path")")")
    
    if [[ "$parent_dir" == "plugins" ]]; then
        target_category="$category_dir"
    else
        target_category="$parent_dir"
    fi
    
    mkdir -p "${PKG_DIR}/usr/lib/qmmp-2.3/${target_category}"
    cp "${plugin_path}" "${PKG_DIR}/usr/lib/qmmp-2.3/${target_category}/${plugin_name}"
done

# 5. Copy desktop files and metainfo
cp src/app/*.desktop "${PKG_DIR}/usr/share/applications/"
cp src/app/metainfo/*.xml "${PKG_DIR}/usr/share/metainfo/"

# 6. Copy and configure icons
echo "Configuring icons..."

# Copy all predefined icons
cp -r src/app/images/* "${PKG_DIR}/usr/share/icons/hicolor/"

# If qmmq.png exists in root, use it as the main icon (renamed to qmmp.png to match desktop file)
if [ -f "qmmq.png" ]; then
    echo "Using qmmq.png from root as the high-resolution icon..."
    mkdir -p "${PKG_DIR}/usr/share/icons/hicolor/512x512/apps"
    cp qmmq.png "${PKG_DIR}/usr/share/icons/hicolor/512x512/apps/qmmp.png"
fi

# 7. Create control file
cat > "${PKG_DIR}/DEBIAN/control" <<EOF
Package: ${PKG_NAME}
Version: ${PKG_VERSION}
Section: sound
Priority: optional
Architecture: ${PKG_ARCH}
Depends: libc6, libstdc++6, libqt6widgets6, libqt6network6, libqt6gui6, libqt6core6, libqt6dbus6, libqt6multimedia6
Maintainer: Ilya Kotov <forkotov02@ya.ru>
Description: Qmmp is an audio-player, written with the help of the Qt library.
 The user interface is similar to winamp or xmms.
EOF

# 8. Create postinst script
cat > "${PKG_DIR}/DEBIAN/postinst" <<EOF
#!/bin/sh
set -e
if [ "\$1" = "configure" ]; then
    ldconfig
    if command -v update-icon-caches >/dev/null 2>&1; then
        update-icon-caches /usr/share/icons/hicolor || true
    elif command -v gtk-update-icon-cache >/dev/null 2>&1; then
        gtk-update-icon-cache -f -t /usr/share/icons/hicolor || true
    fi
fi
EOF
chmod 755 "${PKG_DIR}/DEBIAN/postinst"

# 9. Build the package
echo "Building .deb package..."
dpkg-deb --build "${PKG_DIR}"

echo "Done! Package created: ${PKG_DIR}.deb"
