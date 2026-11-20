include(../../plugins.pri)
TARGET = $$PLUGINS_PREFIX/Ui/classic
QT += widgets concurrent
RESOURCES += skinpackage.cpp classic.qrc
HEADERS += skinpackage.h tracklist.h compactdisplay.h classicskin.h consolecontrols.h classicequalizer.h classicwindow.h windowmagnet.h spectrum.h syncedlyrics.h
SOURCES += skinpackage.cpp tracklist.cpp compactdisplay.cpp classicskin.cpp consolecontrols.cpp classicequalizer.cpp classicfactory.cpp classicwindow.cpp windowmagnet.cpp spectrum.cpp syncedlyrics.cpp
LIBS += $$QMMPUI_LIB -larchive
unix {
    target.path = $$PLUGIN_DIR/Ui
    INSTALLS += target
}
