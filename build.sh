#!/bin/bash

# 1. 设置 Qt 环境路径
QT_PATH="/home/jason/Qt/6.5.3/gcc_64"
QT_CMAKE="$QT_PATH/bin/qt-cmake"

# 2. 定义目录
BUILD_DIR="build-linux"
TEMP_PLUGINS="temp_plugins"

echo "--- 开始编译 Qmmp ---"
echo "使用 Qt 路径: $QT_PATH"

# 3. 创建并进入编译目录
mkdir -p $BUILD_DIR
cd $BUILD_DIR

# 4. 配置项目
echo "--- 正在配置 CMake ---"
$QT_CMAKE .. \
    -DCMAKE_BUILD_TYPE=Release \
    -DUSE_MPG123=ON

# 5. 执行编译
echo "--- 正在编译 ---"
make -j$(nproc)

if [ $? -ne 0 ]; then
    echo "编译失败！"
    exit 1
fi

cd ..

# 6. 设置本地运行的插件目录结构
echo "--- 正在构建本地插件目录 ($TEMP_PLUGINS) ---"
rm -rf $TEMP_PLUGINS
mkdir -p $TEMP_PLUGINS

find $BUILD_DIR/src/plugins -name "*.so" -exec bash -c '
    plugin_path="{}"
    plugin_name=$(basename "$plugin_path")
    category_dir=$(basename "$(dirname "$plugin_path")")
    parent_dir=$(basename "$(dirname "$(dirname "$plugin_path")")")
    if [[ "$parent_dir" == "plugins" ]]; then
        target_category="$category_dir"
    else
        target_category="$parent_dir"
    fi
    mkdir -p "'$TEMP_PLUGINS'/$target_category"
    ln -sf "$(pwd)/$plugin_path" "'$TEMP_PLUGINS'/$target_category/$plugin_name"
' \;

echo "--------------------------------------"
echo "编译完成！"
echo "你可以运行以下命令启动播放器："
echo "export QMMP_PLUGINS=\$(pwd)/$TEMP_PLUGINS"
echo "./$BUILD_DIR/src/app/qmmp"
echo "--------------------------------------"
