# Qmmp 经典中文播放器

基于 Qmmp 2.3.1 和 Qt 6 的本地音乐播放器。经典界面提供播放控制、可拆分的播放列表和同步歌词窗。原有 Skinned 和 QSUI 界面仍可在设置中选择。

## 编译与运行

需要 CMake 3.18 或更新版本、C++17 编译器和 Qt 6.2 或更新版本（含 Widgets、Network 和 LinguistTools）。Ubuntu/Debian 的编解码和构建依赖可用以下命令安装：

```sh
sudo apt install build-essential cmake pkg-config ffmpeg libtag1-dev libmpg123-dev \
    libavcodec-dev libavformat-dev libavutil-dev libasound2-dev libpulse-dev
```

使用独立安装的 Qt SDK 时，将 `QT_PATH` 指向含 `bin/qt-cmake` 的目录。脚本也支持 CMake 能直接找到的 Qt。

```sh
./build.sh
./run.sh
ctest --test-dir build-classic --output-on-failure
```

首次使用默认打开经典中文界面。已有配置会沿用之前选择的界面，可在设置的界面插件列表中选择「经典中文播放器」并重启。打开文件或把歌曲拖进窗口即可播放，空格切换播放和暂停。可用「视图」菜单恢复关闭的歌词窗或播放列表。

## 歌词与解码器

把歌词和歌曲放在同一目录，例如 `春天.flac` 与 `春天.lrc`。支持 UTF-8、GB18030、每行多个时间戳以及 `[offset:毫秒]`。拖动进度或切换歌曲会重新定位歌词。

MPEG 和 FFmpeg 插件提供 MP3、M4A、FLAC、Ogg Vorbis 和 PCM WAV 支持。也可安装专用解码器。Linux 用户可以把与当前 Qt、Qmmp ABI 兼容的解码器放入 `${XDG_CONFIG_HOME:-$HOME/.config}/qmmp/plugins-2.3/Input/`，重启后加载。开发接口见 `src/qmmp/decoderfactory.h` 和 `src/qmmp/decoder.h`。扩展模块编译示例见 `src/plugins/Input/flac/`。

## 打包

`package_deb.sh` 面向 Linux Qt SDK。需要 `dpkg-dev`、`patchelf`、Qt SQLite 和 XCB 平台插件。脚本从同一次构建生成安装包，随包携带私有 Qt 运行库，用 Debian 工具识别系统依赖。

```sh
sudo apt install dpkg-dev patchelf
./package_deb.sh
sudo apt install ./build-classic/dist/qmmp_2.3.1-1_amd64.deb
```

在目标发行版上构建对应架构的包。amd64 文件名如上，其他架构由 `dpkg --print-architecture` 确定。
