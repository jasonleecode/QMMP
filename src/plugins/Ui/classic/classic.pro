include(../../plugins.pri)
TARGET = $$PLUGINS_PREFIX/Ui/classic
QT += widgets
HEADERS += classicwindow.h syncedlyrics.h
SOURCES += classicfactory.cpp classicwindow.cpp syncedlyrics.cpp
LIBS += $$QMMPUI_LIB
unix {
    target.path = $$PLUGIN_DIR/Ui
    INSTALLS += target
}
