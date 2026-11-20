cmake_minimum_required(VERSION 3.18.0 FATAL_ERROR)
project(qmmp)

#freebsd support
if(${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
    include_directories(SYSTEM /usr/local/include)
    link_directories(AFTER /usr/local/lib)
    set(CMAKE_REQUIRED_INCLUDES ${CMAKE_REQUIRED_INCLUDES} /usr/local/include)
endif()

#macports support
if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(CMAKE_REQUIRED_INCLUDES ${CMAKE_REQUIRED_INCLUDES} /opt/local/include)
endif()

if(POLICY CMP0071)
  cmake_policy(SET CMP0071 NEW)
endif()

if(POLICY CMP0063)
    cmake_policy(SET CMP0063 NEW)
endif()

if(POLICY CMP0175)
    cmake_policy(SET CMP0175 NEW)
endif()

#Qt6 modules
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} /home/user/qt6)

#installation paths
include(GNUInstallDirs)
include(FindPkgConfig)

#extract version from qmmp.h
file(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/src/qmmp/qmmp.h"
     QMMP_VERSION_DATA REGEX "^#define[ \t]+QMMP_VERSION_[A-Z]+[ \t]+[0-9]+.*$")

if(QMMP_VERSION_DATA)
    foreach(item IN ITEMS MAJOR MINOR PATCH STABLE)
        string(REGEX REPLACE ".*#define[ \t]+QMMP_VERSION_${item}[ \t]+([0-9]+).*"
        "\\1" QMMP_VERSION_${item} ${QMMP_VERSION_DATA})
    endforeach(item IN ITEMS MAJOR MINOR PATCH)

    set(QMMP_VERSION "${QMMP_VERSION_MAJOR}.${QMMP_VERSION_MINOR}.${QMMP_VERSION_PATCH}")
    set(QMMP_SOVERSION "${QMMP_VERSION_MAJOR}")

    if(QMMP_VERSION_STABLE)
       message(STATUS "Qmmp API version: ${QMMP_VERSION} (stable)")
    else(QMMP_VERSION_STABLE)
       message(STATUS "Qmmp API version: ${QMMP_VERSION} (development)")
    endif(QMMP_VERSION_STABLE)
else(QMMP_VERSION_DATA)
    message(FATAL_ERROR "invalid header")
endif(QMMP_VERSION_DATA)

configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
  IMMEDIATE @ONLY)

add_custom_target(uninstall
  "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_definitions(-DQT_DISABLE_DEPRECATED_BEFORE=0x060200 -DQT_DEPRECATED_WARNINGS -DQT_MESSAGELOGCONTEXT)
add_compile_options(-Wall -Wextra)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src) #libqmmp & libqmmpui

find_package(Qt6 6.2 CONFIG REQUIRED COMPONENTS Widgets LinguistTools Network)
find_package(Qt6 6.2 CONFIG OPTIONAL_COMPONENTS DBus OpenGLWidgets Sql Multimedia)

get_target_property(QT_LRELEASE_EXECUTABLE Qt6::lrelease IMPORTED_LOCATION)

if(QT_LRELEASE_EXECUTABLE)
    message(STATUS "Found lrelease executable: " ${QT_LRELEASE_EXECUTABLE})
else(QT_LRELEASE_EXECUTABLE)
    message(FATAL_ERROR "Could NOT find lrelease executable")
endif(QT_LRELEASE_EXECUTABLE)

message(STATUS "Generating translations ...")

file(GLOB_RECURSE translation_sources "${CMAKE_CURRENT_SOURCE_DIR}/src/*.ts")
set(lrelease_options -silent)
if(SVN_VERSION)
    list(APPEND lrelease_options -nounfinished)
endif()
set(pending_translations)
foreach(source IN LISTS translation_sources)
    string(REGEX REPLACE "[.]ts$" ".qm" output "${source}")
    if(NOT "${lrelease_options}" STREQUAL "${last_lrelease_options}" OR
       NOT EXISTS "${output}" OR "${source}" IS_NEWER_THAN "${output}")
        list(APPEND pending_translations "${source}")
    endif()
endforeach()
# Batch files to stay within the Windows command-line length limit.
while(pending_translations)
    list(SUBLIST pending_translations 0 50 batch)
    execute_process(COMMAND "${QT_LRELEASE_EXECUTABLE}" ${lrelease_options} ${batch}
                    RESULT_VARIABLE result)
    if(NOT result EQUAL 0)
        message(FATAL_ERROR "lrelease failed: ${result}")
    endif()
    list(REMOVE_ITEM pending_translations ${batch})
endwhile()
set(last_lrelease_options "${lrelease_options}" CACHE INTERNAL "Last translation compiler options")

set(PLUGIN_DIR "${CMAKE_INSTALL_LIBDIR}/qmmp-${QMMP_VERSION_MAJOR}.${QMMP_VERSION_MINOR}" CACHE STRING "plugin path")
option(USE_SKINNED "standard skinned user interface" ON)
option(USE_DIR_ASSOC "inode/directory mime type association" ON)
#set(APP_NAME_SUFFIX "-1")

get_target_property(QtGui_enabled_features Qt6::Gui QT_ENABLED_PUBLIC_FEATURES)
if("xcb" IN_LIST QtGui_enabled_features)
    pkg_search_module(X11 x11 IMPORTED_TARGET)
    set(XCB_ENABLED YES)
    add_definitions(-DQMMP_WS_X11)
endif()

if(X11_FOUND OR NOT XCB_ENABLED)
    set(SKINNED_AVAILABLE YES)
endif()

add_subdirectory(src/qmmp)
add_subdirectory(src/qmmpui)
add_subdirectory(src/plugins)
add_subdirectory(src/app)
add_subdirectory(doc)

if(MAD_FOUND)
    set(MPEG_DECODERS "MAD")
endif(MAD_FOUND)

if(MPG123_FOUND)
    set(MPEG_DECODERS ${MPEG_DECODERS} "mpg123")
endif(MPG123_FOUND)

if(XCB_FOUND OR WIN32)
    set(HOTKEY_AVAYLABLE YES)
endif()

macro(PRINT_SUMMARY str USE FOUND)
    if(${USE} AND ${FOUND})
        message("${str}enabled")
    else(${USE} AND ${FOUND})
        message("${str}disabled")
    endif(${USE} AND ${FOUND})
endmacro(PRINT_SUMMARY)


add_custom_target(distclean @echo cleaning for source distribution)

add_custom_command(
    POST_BUILD
    COMMENT "distribution clean"
    COMMAND ${CMAKE_MAKE_PROGRAM}
    ARGS -C ${CMAKE_CURRENT_BINARY_DIR} clean
    COMMAND find
    ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "CMakeCache.txt" | xargs rm -rf
    COMMAND find
    ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "CMakeFiles" | xargs rm -rf
    COMMAND find
    ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "Makefile" | xargs rm -rf
    COMMAND find
    ARGS ${CMAKE_CURRENT_BINARY_DIR} -name \"*.cmake\" | xargs rm -rf
    COMMAND find
    ARGS ${CMAKE_CURRENT_SOURCE_DIR} -name "*.qm" | xargs rm -rf
    COMMAND find
    ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "*.pc" | xargs rm -rf
    COMMAND find
    ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "*.depends" | xargs rm -rf
    COMMAND find
    ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "*.cxx_parameters" | xargs rm -rf
    COMMAND find
    ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "moc_*.cpp" | xargs rm -rf
    COMMAND find
    ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "qrc_*.cxx" | xargs rm -rf
    COMMAND find
    ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "*_automoc.cpp" | xargs rm -rf
    COMMAND rm
    ARGS -rf ${CMAKE_CURRENT_BINARY_DIR}/install_manifest.txt
    COMMAND find
    ARGS ${CMAKE_CURRENT_BINARY_DIR} -name *_automoc.dir | xargs rm -rf
    COMMAND rm
    ARGS -rf ${CMAKE_CURRENT_BINARY_DIR}/doc/html .qt config.tests build.ninja .ninja_deps
    TARGET  distclean
)

message("")
message("Transports:")
PRINT_SUMMARY ("HTTP support .........................." USE_CURL CURL_FOUND)

message("")
message("Input Plugins:")
PRINT_SUMMARY ("MPEG support .........................." 1 MPEG_DECODERS)
PRINT_SUMMARY ("FLAC support .........................." USE_FLAC FLAC_FOUND)
PRINT_SUMMARY ("Ogg Vorbis support ...................." USE_VORBIS VORBIS_FOUND)
PRINT_SUMMARY ("Musepack support ......................" USE_MPC MPC_FOUND)
PRINT_SUMMARY ("MOD support ..........................." USE_XMP XMP_FOUND)
PRINT_SUMMARY ("Wave support .........................." USE_SNDFILE SNDFILE_FOUND)
PRINT_SUMMARY ("WavPack support ......................." USE_WAVPACK WAVPACK_FOUND)
PRINT_SUMMARY ("FFmpeg support ........................" USE_FFMPEG FFMPEG_FOUND)
PRINT_SUMMARY ("AAC support ..........................." USE_AAC FAAD_FOUND)
PRINT_SUMMARY ("CUE sheet support ....................." USE_CUE 1)
PRINT_SUMMARY ("CD Audio support ......................" USE_CDA CDIO_FOUND)
PRINT_SUMMARY ("Midi support .........................." USE_MIDI WILDMIDI_FOUND)
PRINT_SUMMARY ("Game music support ...................." USE_GME GME_FOUND)
PRINT_SUMMARY ("Ogg Opus support ......................" USE_OPUS OPUS_FOUND)
PRINT_SUMMARY ("SID support ..........................." USE_SID SIDPLAYFP_FOUND)
PRINT_SUMMARY ("Archive support ......................." USE_ARCHIVE LIBARCHIVE_FOUND)

message("")
message("Output Plugins:")
PRINT_SUMMARY ("ALSA support .........................." USE_ALSA ALSA_FOUND)
PRINT_SUMMARY ("OSS support ..........................." USE_OSS 1)
PRINT_SUMMARY ("OSS4 support .........................." USE_OSS4 OSS4_FOUND)
PRINT_SUMMARY ("JACK support .........................." USE_JACK JACK_FOUND)
PRINT_SUMMARY ("PulseAudio support ...................." USE_PULSE PULSE_FOUND)
PRINT_SUMMARY ("PipeWire support ......................" USE_PIPEWIRE PIPEWIRE_FOUND)
PRINT_SUMMARY ("Null output support ..................." USE_NULL 1)
PRINT_SUMMARY ("Waveout support (Windows) ............." USE_WAVEOUT WINDOWS_H_FOUND)
PRINT_SUMMARY ("DirectSound support (Windows) ........." USE_DSOUND DSOUND_H_FOUND)
PRINT_SUMMARY ("WASAPI support (Windows) .............." USE_WASAPI WASAPI_FOUND)
PRINT_SUMMARY ("Qt Multimedia support ................." USE_QTMULTIMEDIA Qt6Multimedia_FOUND)
PRINT_SUMMARY ("Icecast support ......................." USE_SHOUT SHOUT_FOUND)

message("")
message("Effect Plugins:")
PRINT_SUMMARY ("SoX Resampler ........................." USE_SOXR SOXR_FOUND)
PRINT_SUMMARY ("BS2B Plugin ..........................." USE_BS2B BS2B_FOUND)
PRINT_SUMMARY ("LADSPA Host ..........................." USE_LADSPA DLFCN_H_FOUND)
PRINT_SUMMARY ("Crossfade ............................." USE_CROSSFADE 1)
PRINT_SUMMARY ("Extra Stereo .........................." USE_STEREO 1)
PRINT_SUMMARY ("File Writer ..........................." USE_FILEWRITER VORBISENC_FOUND)
PRINT_SUMMARY ("Mono to Stereo Converter .............." USE_MONOTOSTEREO 1)

message("")
message("Visual Plugins:")
PRINT_SUMMARY ("Analyzer .............................." USE_ANALYZER 1)
PRINT_SUMMARY ("ProjectM .............................." USE_PROJECTM PROJECTM_FOUND)

message("")
message("General Plugins:")
PRINT_SUMMARY ("MPRIS support ........................." USE_MPRIS Qt6DBus_FOUND)
PRINT_SUMMARY ("Scrobbler ............................." USE_SCROBBLER 1)
PRINT_SUMMARY ("ListenBrainz .........................." USE_LISTENBRAINZ 1)
PRINT_SUMMARY ("Tray support .........................." USE_STATICON 1)
PRINT_SUMMARY ("Notifier support ......................" USE_NOTIFIER 1)
PRINT_SUMMARY ("Lyrics support ........................" USE_LYRICS 1)
PRINT_SUMMARY ("UDisks support ......,................." USE_UDISKS Qt6DBus_FOUND)
PRINT_SUMMARY ("Global hotkey support ................." USE_HOTKEY HOTKEY_AVAYLABLE)
PRINT_SUMMARY ("GNOME/Cinnamon hotkey support ........." USE_GNOMEHOTKEY Qt6DBus_FOUND)
PRINT_SUMMARY ("File operations ......................." USE_FILEOPS 1)
PRINT_SUMMARY ("Cover manager ........................." USE_COVER 1)
PRINT_SUMMARY ("KDE notifications support ............." USE_KDENOTIFY Qt6DBus_FOUND)
PRINT_SUMMARY ("Audio converter ......................." USE_CONVERTER TAGLIB_FOUND)
PRINT_SUMMARY ("ReplayGain Scanner ...................." USE_RGSCAN TAGLIB_FOUND)
PRINT_SUMMARY ("Stream browser ........................" USE_SB 1)
PRINT_SUMMARY ("Track change .........................." USE_TRACKCHANGE 1)
PRINT_SUMMARY ("Copy/Paste ............................" USE_COPYPASTE 1)
PRINT_SUMMARY ("History plugin ........................" USE_HISTORY Qt6Sql_FOUND)
PRINT_SUMMARY ("Sleep mode inhibition plugin .........." USE_SLEEPINHIBITOR Qt6DBus_FOUND)
PRINT_SUMMARY ("Media library plugin .................." USE_LIBRARY Qt6Sql_FOUND)
PRINT_SUMMARY ("Taskbar plugin (Windows) .............." USE_TASKBAR WIN32)
PRINT_SUMMARY ("Removable device detection (Windows) .." USE_RDETECT WIN32)

message("")
message("File Dialogs:")
PRINT_SUMMARY ("QMMP File Dialog ......................" USE_QMMP_DIALOG 1)
PRINT_SUMMARY ("Two-panel File File Dialog ............" USE_TWO_PANEL_DIALOG 1)

message("")
message("User Interfaces:")
PRINT_SUMMARY ("Skinned user interface ................" USE_SKINNED SKINNED_AVAILABLE)
PRINT_SUMMARY ("Simple user interface (QSUI) .........." USE_QSUI 1)

message("")
message("Advanced:")
PRINT_SUMMARY ("Automatic charset detection ..........." USE_ENCA ENCA_FOUND)
PRINT_SUMMARY ("MPEG plugin with LibRCD support ......." USE_LIBRCD LIBRCD_FOUND)
PRINT_SUMMARY ("CD Audio plugin with CDDB support ....." USE_LIBCDDB CDDB_FOUND)
PRINT_SUMMARY ("Directory association ................." USE_DIR_ASSOC 1)
PRINT_SUMMARY ("Set RPATH in installed binaries ......." CMAKE_INSTALL_RPATH_USE_LINK_PATH 1)
if(MPEG_DECODERS)
    message   ("MPEG decoders ........................." "${MPEG_DECODERS}")
endif(MPEG_DECODERS)

message("")

include(CTest)
if(BUILD_TESTING AND CMAKE_SYSTEM_NAME STREQUAL "Linux" AND TARGET qtmultimedia)
    find_program(PULSEAUDIO_EXECUTABLE pulseaudio)
    find_program(DBUS_RUN_SESSION_EXECUTABLE dbus-run-session)
    if(PULSEAUDIO_EXECUTABLE AND DBUS_RUN_SESSION_EXECUTABLE)
        add_executable(qtmultimedia_seek_test tests/qtmultimedia_seek.cpp)
        target_link_libraries(qtmultimedia_seek_test PRIVATE Qt6::Widgets Qt6::Multimedia libqmmp)
        add_test(NAME qtmultimedia_seek COMMAND ${DBUS_RUN_SESSION_EXECUTABLE} --
                 $<TARGET_FILE:qtmultimedia_seek_test> ${PULSEAUDIO_EXECUTABLE} $<TARGET_FILE:qtmultimedia>)
        set_tests_properties(qtmultimedia_seek PROPERTIES ENVIRONMENT "QT_QPA_PLATFORM=offscreen"
                             SKIP_RETURN_CODE 77 TIMEOUT 20)
    endif()
endif()
if(BUILD_TESTING AND TARGET classic)
    add_executable(windowmagnet_test tests/windowmagnet.cpp src/plugins/Ui/classic/windowmagnet.cpp)
    target_link_libraries(windowmagnet_test PRIVATE Qt6::Widgets)
    add_test(NAME windowmagnet COMMAND windowmagnet_test)
    set_tests_properties(windowmagnet PROPERTIES ENVIRONMENT "QT_QPA_PLATFORM=offscreen")
endif()
if(BUILD_TESTING AND UNIX AND TARGET classic AND TARGET mpeg AND TARGET ffmpeg AND TARGET null)
    find_program(FFMPEG_EXECUTABLE ffmpeg)
    if(FFMPEG_EXECUTABLE)
        add_executable(classic_playback_test tests/classic_playback.cpp)
        target_link_libraries(classic_playback_test PRIVATE Qt6::Widgets libqmmpui libqmmp)
        add_test(NAME classic_playback COMMAND classic_playback_test
                 ${FFMPEG_EXECUTABLE} $<TARGET_FILE:classic> $<TARGET_FILE:mpeg>
                 $<TARGET_FILE:ffmpeg> $<TARGET_FILE:null>)
        set_tests_properties(classic_playback PROPERTIES ENVIRONMENT "QT_QPA_PLATFORM=offscreen" TIMEOUT 40)
    endif()
endif()
