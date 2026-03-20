# Install script for directory: /home/lixiang/Downloads/qmmp-2.3.1/src/qmmp

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libqmmp.so.2.3.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libqmmp.so.2"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/lixiang/Downloads/qmmp-2.3.1/build-linux/src/qmmp/libqmmp.so.2.3.1"
    "/home/lixiang/Downloads/qmmp-2.3.1/build-linux/src/qmmp/libqmmp.so.2"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libqmmp.so.2.3.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libqmmp.so.2"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/home/lixiang/Qt/6.5.3/gcc_64/lib:"
           NEW_RPATH "")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/lixiang/Downloads/qmmp-2.3.1/build-linux/src/qmmp/libqmmp.so")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/qmmp" TYPE FILE FILES
    "/home/lixiang/Downloads/qmmp-2.3.1/src/qmmp/abstractengine.h"
    "/home/lixiang/Downloads/qmmp-2.3.1/src/qmmp/audioconverter.h"
    "/home/lixiang/Downloads/qmmp-2.3.1/src/qmmp/audioparameters.h"
    "/home/lixiang/Downloads/qmmp-2.3.1/src/qmmp/buffer.h"
    "/home/lixiang/Downloads/qmmp-2.3.1/src/qmmp/channelmap.h"
    "/home/lixiang/Downloads/qmmp-2.3.1/src/qmmp/cueparser.h"
    "/home/lixiang/Downloads/qmmp-2.3.1/src/qmmp/decoderfactory.h"
    "/home/lixiang/Downloads/qmmp-2.3.1/src/qmmp/decoder.h"
    "/home/lixiang/Downloads/qmmp-2.3.1/src/qmmp/effectfactory.h"
    "/home/lixiang/Downloads/qmmp-2.3.1/src/qmmp/effect.h"
    "/home/lixiang/Downloads/qmmp-2.3.1/src/qmmp/enginefactory.h"
    "/home/lixiang/Downloads/qmmp-2.3.1/src/qmmp/eqsettings.h"
    "/home/lixiang/Downloads/qmmp-2.3.1/src/qmmp/inputsourcefactory.h"
    "/home/lixiang/Downloads/qmmp-2.3.1/src/qmmp/inputsource.h"
    "/home/lixiang/Downloads/qmmp-2.3.1/src/qmmp/metadatamanager.h"
    "/home/lixiang/Downloads/qmmp-2.3.1/src/qmmp/metadatamodel.h"
    "/home/lixiang/Downloads/qmmp-2.3.1/src/qmmp/outputfactory.h"
    "/home/lixiang/Downloads/qmmp-2.3.1/src/qmmp/output.h"
    "/home/lixiang/Downloads/qmmp-2.3.1/src/qmmp/qmmp_export.h"
    "/home/lixiang/Downloads/qmmp-2.3.1/src/qmmp/qmmp.h"
    "/home/lixiang/Downloads/qmmp-2.3.1/src/qmmp/qmmpsettings.h"
    "/home/lixiang/Downloads/qmmp-2.3.1/src/qmmp/qmmptextcodec.h"
    "/home/lixiang/Downloads/qmmp-2.3.1/src/qmmp/soundcore.h"
    "/home/lixiang/Downloads/qmmp-2.3.1/src/qmmp/statehandler.h"
    "/home/lixiang/Downloads/qmmp-2.3.1/src/qmmp/tagmodel.h"
    "/home/lixiang/Downloads/qmmp-2.3.1/src/qmmp/trackinfo.h"
    "/home/lixiang/Downloads/qmmp-2.3.1/src/qmmp/visualfactory.h"
    "/home/lixiang/Downloads/qmmp-2.3.1/src/qmmp/visual.h"
    "/home/lixiang/Downloads/qmmp-2.3.1/src/qmmp/volume.h"
    "/home/lixiang/Downloads/qmmp-2.3.1/src/qmmp/volumehandler.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/lixiang/Downloads/qmmp-2.3.1/build-linux/src/qmmp/qmmp.pc")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "/home/lixiang/Downloads/qmmp-2.3.1/build-linux/src/qmmp/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
