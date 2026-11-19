#!/usr/bin/env bash
set -euo pipefail
root=$(cd "$(dirname "$0")" && pwd)
build_dir=${BUILD_DIR:-"$root/build-classic"}
stage=$(realpath -m "$build_dir/stage/usr")
if [[ ! -x "$stage/bin/qmmp" ]]; then
    echo "请先运行 ./build.sh" >&2
    exit 1
fi
qt_dir=$(sed -n 's|^Qt6_DIR:PATH=\(.*\)/lib/cmake/Qt6$|\1|p' "$build_dir/CMakeCache.txt")
export QMMP_PLUGINS=${QMMP_PLUGINS:-"$stage/lib/qmmp-2.3"}
export LD_LIBRARY_PATH="$stage/lib${qt_dir:+:$qt_dir/lib}${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"
exec "$stage/bin/qmmp" "$@"
