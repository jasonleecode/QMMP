add_library(classic MODULE classicfactory.cpp classicwindow.cpp syncedlyrics.cpp)
target_link_libraries(classic PRIVATE Qt6::Widgets libqmmpui libqmmp)
install(TARGETS classic DESTINATION ${PLUGIN_DIR}/Ui)
