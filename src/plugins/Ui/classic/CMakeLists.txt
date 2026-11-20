add_library(classic MODULE classic.qrc classicskin.cpp consolecontrols.cpp classicequalizer.cpp classicfactory.cpp classicwindow.cpp windowmagnet.cpp spectrum.cpp syncedlyrics.cpp)
target_link_libraries(classic PRIVATE Qt6::Widgets libqmmpui libqmmp)
install(TARGETS classic DESTINATION ${PLUGIN_DIR}/Ui)
