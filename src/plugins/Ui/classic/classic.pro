include(../../plugins.pri)
TARGET = $$PLUGINS_PREFIX/Ui/classic
QT += widgets
HEADERS += classicwindow.h windowmagnet.h spectrum.h syncedlyrics.h
SOURCES += classicfactory.cpp classicwindow.cpp windowmagnet.cpp spectrum.cpp syncedlyrics.cpp
LIBS += $$QMMPUI_LIB
unix {
    target.path = $$PLUGIN_DIR/Ui
    INSTALLS += target
}
