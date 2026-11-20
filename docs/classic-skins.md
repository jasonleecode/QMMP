# 制作和分享经典界面皮肤

「琥珀静听」可直接从左上角的「皮肤」菜单选择。分享给别人时，只需要发送一个 `.qmmp-skin` 文件。接收者在「皮肤 → 载入皮肤…」中选中它即可生效。播放器会把完整的包复制到自己的配置目录，之后移动或删除下载文件也能使用。[下载示例皮肤](../skins/amber.qmmp-skin)

千千静听社区复刻项目记载了原版的文件组织方式。外部 `.skn` 是 ZIP，里面的 XML 描述窗口和控件，位图提供外观。Qmmp 的经典界面也将描述文件和素材放入一个 ZIP，采用自己的版本化 XML 清单。原版 `.skn` 使用另一套控件和位图状态定义，不能直接导入。[千千静听社区复刻项目](https://github.com/Sonic853/TTPlayer)

## 从现有皮肤开始

解压示例包，或复制仓库中的琥珀皮肤目录。开发时可直接载入目录中的 `skin.xml`；修改后在皮肤菜单中再次点击它即可重新加载。准备分享时，从目录内部打包，让 `skin.xml` 位于 ZIP 的根目录。

```sh
cd src/plugins/Ui/classic/skins/amber
zip -r ~/amber.qmmp-skin skin.xml style.qss *.svg
```

播放器也接受使用 `.zip` 后缀的同格式文件。单个包和展开后的素材各限 32 MiB，最多 512 个条目，素材路径相对于包根目录。旧版 INI 皮肤继续使用原有的同目录 QSS 和素材。[示例源文件](../src/plugins/Ui/classic/skins/amber)

## 清单字段

清单根元素为 `<qmmp-skin version="1" name="皮肤名称">`。只提供名称与十一种基础色也可以加载，其余项使用经典布局的默认值。

| 元素 | 可设置的属性 | 效果 |
| --- | --- | --- |
| `colors` | `edge shadow body metal shine display glow accent spectrum text muted` | 提供基础样式、文字和可视化使用的颜色。使用 `#RRGGBB` 值。 |
| `layout` | `clock="left\|right"`、`playlistTools="top\|bottom"` | 移动歌曲计时和列表工具栏。 |
| `layout` | `volume`、`panelSwitches` 分别可取 `display` 或 `transport` | 决定音量调节和面板开关放在显示区还是播放键旁。 |
| `layout` | `volumeReadout`、`flatKeys` 取 `true` 或 `false` | 显示音量百分比，或使用平面播放键。 |
| `layout` | `keyWidth/Height`、`playWidth/Height`、`libraryWidth/Height`、`keySpacing`、`volumeWidth`、`screenMargin`、`screenSpacing` | 控制按键、边距和间距，单位为 Qt 逻辑像素。例如播放键宽度属性为 `playWidth`。 |
| `layout` | `mainHeight`、`playlistHeight`、`lyricsHeight`、`libraryText` | 指定首次显示主机的高度、磁吸排列时的面板高度，以及音乐窗按钮的文本。 |
| `captions` | `main`、`equalizer`、`playlist`、`lyrics` | 设置四个窗口的标题栏文字。 |
| `artwork` | `emblem` | 指定主菜单和迷你横条使用的图标，例如 `emblem.svg`。 |
| `icon`（可重复） | `action`、`file`，可选 `hover`、`pressed`、`disabled` | 用自己的图片替换指定动作的图标，并为不同状态提供素材。例如 `<icon action="next" file="next.svg"/>`。 |
| `style` | `file` | 指定附加的 Qt 样式表，例如 `style.qss`。 |

可替换的动作有 `play pause stop previous next eject minimize compact restore close speaker mute sequential shuffle`。迷你显示屏支持 `QLabel#compactTitle` 的 `qproperty-backlight` 和 `qproperty-ink` 颜色。

QSS 可以设置菜单、弹窗、按钮的悬停和按下状态、滑块、列表和面板背景。使用 `@颜色名@` 引用清单颜色，使用 `url("@SKIN_DIR@/文件名")` 引用包内素材。EQ、切歌、进度拖动等操作仍由播放器的同一组控件处理。[控件选择器与基础样式](../src/plugins/Ui/classic/skins/classic.qss)
