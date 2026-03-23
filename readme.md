# Qmmp (Qt-based Multimedia Player)

基于 Qt 的开源多媒体播放器，提供经典的 Winamp/XMMS 风格界面。

### 核心优点
- **轻量高效**：极低的系统资源占用，启动迅速。
- **高度定制**：完美支持经典皮肤（Skins）及丰富的插件体系。
- **全格式支持**：原生支持 MP3, FLAC, Ogg Vorbis, AAC, WavPack 等主流音频格式。
- **现代架构**：基于 Qt6 构建，支持高分屏（DPI）及多平台运行。

## 编译依赖 (Ubuntu/Debian)

```bash
sudo apt install build-essential cmake pkg-config patchelf \
                 libtag1-dev libmad0-dev libmpg123-dev
```

## 编译与运行

1. **编译**: `./build.sh`
2. **运行**: `./run.sh`

## 打包 (DEB)

生成的安装包将自带 Qt6 运行库：
```bash
./package_deb.sh
sudo dpkg -i qmmp_2.3.1_amd64.deb
```
