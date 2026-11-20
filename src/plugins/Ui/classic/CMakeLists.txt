find_package(Qt6 REQUIRED COMPONENTS Concurrent)
add_library(classic MODULE classic.qrc tracklist.cpp compactdisplay.cpp classicskin.cpp consolecontrols.cpp classicequalizer.cpp classicfactory.cpp classicwindow.cpp windowmagnet.cpp spectrum.cpp syncedlyrics.cpp)
target_link_libraries(classic PRIVATE Qt6::Widgets Qt6::Concurrent libqmmpui libqmmp)
install(TARGETS classic DESTINATION ${PLUGIN_DIR}/Ui)
