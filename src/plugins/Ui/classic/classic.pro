include(../../plugins.pri)
TARGET = $$PLUGINS_PREFIX/Ui/classic
QT += widgets concurrent
RESOURCES += classic.qrc
HEADERS += tracklist.h compactdisplay.h classicskin.h consolecontrols.h classicequalizer.h classicwindow.h windowmagnet.h spectrum.h syncedlyrics.h
SOURCES += tracklist.cpp compactdisplay.cpp classicskin.cpp consolecontrols.cpp classicequalizer.cpp classicfactory.cpp classicwindow.cpp windowmagnet.cpp spectrum.cpp syncedlyrics.cpp
LIBS += $$QMMPUI_LIB
unix {
    target.path = $$PLUGIN_DIR/Ui
    INSTALLS += target
}
