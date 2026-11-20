include(../../plugins.pri)
TARGET = $$PLUGINS_PREFIX/Ui/classic
QT += widgets
RESOURCES += classic.qrc
HEADERS += classicskin.h consolecontrols.h classicequalizer.h classicwindow.h windowmagnet.h spectrum.h syncedlyrics.h
SOURCES += classicskin.cpp consolecontrols.cpp classicequalizer.cpp classicfactory.cpp classicwindow.cpp windowmagnet.cpp spectrum.cpp syncedlyrics.cpp
LIBS += $$QMMPUI_LIB
unix {
    target.path = $$PLUGIN_DIR/Ui
    INSTALLS += target
}
