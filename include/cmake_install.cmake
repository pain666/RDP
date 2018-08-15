# Install script for directory: D:/GitHub/FreeRDP/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/FreeRDP")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xheadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/freerdp2/freerdp" TYPE FILE FILES
    "D:/GitHub/FreeRDP/include/freerdp/addin.h"
    "D:/GitHub/FreeRDP/include/freerdp/altsec.h"
    "D:/GitHub/FreeRDP/include/freerdp/api.h"
    "D:/GitHub/FreeRDP/include/freerdp/assistance.h"
    "D:/GitHub/FreeRDP/include/freerdp/autodetect.h"
    "D:/GitHub/FreeRDP/include/freerdp/build-config.h"
    "D:/GitHub/FreeRDP/include/freerdp/client.h"
    "D:/GitHub/FreeRDP/include/freerdp/codecs.h"
    "D:/GitHub/FreeRDP/include/freerdp/constants.h"
    "D:/GitHub/FreeRDP/include/freerdp/dvc.h"
    "D:/GitHub/FreeRDP/include/freerdp/error.h"
    "D:/GitHub/FreeRDP/include/freerdp/event.h"
    "D:/GitHub/FreeRDP/include/freerdp/extension.h"
    "D:/GitHub/FreeRDP/include/freerdp/freerdp.h"
    "D:/GitHub/FreeRDP/include/freerdp/graphics.h"
    "D:/GitHub/FreeRDP/include/freerdp/input.h"
    "D:/GitHub/FreeRDP/include/freerdp/listener.h"
    "D:/GitHub/FreeRDP/include/freerdp/log.h"
    "D:/GitHub/FreeRDP/include/freerdp/message.h"
    "D:/GitHub/FreeRDP/include/freerdp/metrics.h"
    "D:/GitHub/FreeRDP/include/freerdp/peer.h"
    "D:/GitHub/FreeRDP/include/freerdp/pointer.h"
    "D:/GitHub/FreeRDP/include/freerdp/primary.h"
    "D:/GitHub/FreeRDP/include/freerdp/primitives.h"
    "D:/GitHub/FreeRDP/include/freerdp/rail.h"
    "D:/GitHub/FreeRDP/include/freerdp/scancode.h"
    "D:/GitHub/FreeRDP/include/freerdp/secondary.h"
    "D:/GitHub/FreeRDP/include/freerdp/session.h"
    "D:/GitHub/FreeRDP/include/freerdp/settings.h"
    "D:/GitHub/FreeRDP/include/freerdp/svc.h"
    "D:/GitHub/FreeRDP/include/freerdp/types.h"
    "D:/GitHub/FreeRDP/include/freerdp/update.h"
    "D:/GitHub/FreeRDP/include/freerdp/version.h"
    "D:/GitHub/FreeRDP/include/freerdp/window.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xheadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/freerdp2/freerdp" TYPE FILE FILES "D:/GitHub/FreeRDP/include/freerdp/version.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xheadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/freerdp2/freerdp" TYPE FILE FILES "D:/GitHub/FreeRDP/include/freerdp/build-config.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xheadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/freerdp2/freerdp" TYPE DIRECTORY FILES "D:/GitHub/FreeRDP/include/freerdp/cache" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xheadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/freerdp2/freerdp" TYPE DIRECTORY FILES "D:/GitHub/FreeRDP/include/freerdp/codec" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xheadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/freerdp2/freerdp" TYPE DIRECTORY FILES "D:/GitHub/FreeRDP/include/freerdp/crypto" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xheadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/freerdp2/freerdp" TYPE DIRECTORY FILES "D:/GitHub/FreeRDP/include/freerdp/gdi" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xheadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/freerdp2/freerdp" TYPE DIRECTORY FILES "D:/GitHub/FreeRDP/include/freerdp/locale" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xheadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/freerdp2/freerdp" TYPE DIRECTORY FILES "D:/GitHub/FreeRDP/include/freerdp/utils" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xheadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/freerdp2/freerdp" TYPE DIRECTORY FILES "D:/GitHub/FreeRDP/include/freerdp/client" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xheadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/freerdp2/freerdp" TYPE DIRECTORY FILES "D:/GitHub/FreeRDP/include/freerdp/server" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xheadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/freerdp2/freerdp" TYPE DIRECTORY FILES "D:/GitHub/FreeRDP/include/freerdp/channels" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

