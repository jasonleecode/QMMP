#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")"
build_dir=${BUILD_DIR:-build-classic}
options=(-DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_INSTALL_LIBDIR=lib
         -DPLUGIN_DIR=lib/qmmp-2.3 -DQMMP_DEFAULT_UI=classic)
if [[ -n ${QT_PATH:-} ]]; then
    options+=("-DCMAKE_PREFIX_PATH=$QT_PATH")
elif [[ -x "$HOME/Qt/6.5.3/gcc_64/bin/qt-cmake" ]]; then
    options+=("-DCMAKE_PREFIX_PATH=$HOME/Qt/6.5.3/gcc_64")
fi
cmake -S . -B "$build_dir" "${options[@]}" "$@"
cmake --build "$build_dir" --parallel "${CMAKE_BUILD_PARALLEL_LEVEL:-8}"
stage=$(realpath -m "$build_dir/stage")
DESTDIR="$stage" cmake --install "$build_dir"
echo "构建完成，可运行 ./run.sh"
