#!/bin/bash

# Get current directory
ROOT_DIR="$(pwd)"
BUILD_DIR="${ROOT_DIR}/build-linux"
TEMP_PLUGINS="${ROOT_DIR}/temp_plugins"
QT_LIB_DIR="/home/lixiang/Qt/6.5.3/gcc_64/lib"

# 1. Recreate temp_plugins to ensure symlinks are correct for this location
echo "Updating plugin directory structure..."
rm -rf "${TEMP_PLUGINS}"
mkdir -p "${TEMP_PLUGINS}"

find "${BUILD_DIR}/src/plugins" -name "*.so" | while read -r plugin_path; do
    plugin_name=$(basename "$plugin_path")
    category_dir=$(basename "$(dirname "$plugin_path")")
    parent_dir=$(basename "$(dirname "$(dirname "$plugin_path")")")
    
    if [[ "$parent_dir" == "plugins" ]]; then
        target_category="$category_dir"
    else
        target_category="$parent_dir"
    fi
    
    mkdir -p "${TEMP_PLUGINS}/${target_category}"
    ln -sf "${plugin_path}" "${TEMP_PLUGINS}/${target_category}/${plugin_name}"
done

# 2. Set environment variables
export QMMP_PLUGINS="${TEMP_PLUGINS}"
export LD_LIBRARY_PATH="${BUILD_DIR}/src/qmmp:${BUILD_DIR}/src/qmmpui:${QT_LIB_DIR}${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}"

# 3. Run QMMP
echo "Starting QMMP..."
exec "${BUILD_DIR}/src/app/qmmp" "$@"
