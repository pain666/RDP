# Install script for directory: D:/GitHub/FreeRDP/winpr/include

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/winpr2/winpr" TYPE FILE FILES
    "D:/GitHub/FreeRDP/winpr/include/winpr/asn1.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/bcrypt.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/bitstream.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/clipboard.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/cmdline.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/collections.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/comm.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/credentials.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/credui.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/crt.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/crypto.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/debug.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/dsparse.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/endian.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/environment.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/error.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/file.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/handle.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/heap.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/image.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/ini.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/input.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/interlocked.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/intrin.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/io.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/library.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/locale.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/memory.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/midl.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/ndr.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/nt.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/ntlm.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/pack.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/path.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/pipe.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/platform.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/pool.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/print.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/registry.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/rpc.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/sam.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/schannel.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/security.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/shell.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/smartcard.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/spec.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/ssl.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/sspi.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/sspicli.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/stream.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/string.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/strlst.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/synch.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/sysinfo.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/tchar.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/thread.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/timezone.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/user.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/version.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/windows.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/winhttp.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/winpr.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/winsock.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/wlog.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/wnd.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/wtsapi.h"
    "D:/GitHub/FreeRDP/winpr/include/winpr/wtypes.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xheadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/winpr2/winpr" TYPE FILE FILES "D:/GitHub/FreeRDP/winpr/include/winpr/version.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xheadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/winpr2/winpr" TYPE FILE FILES "D:/GitHub/FreeRDP/winpr/include/winpr/wtypes.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xheadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/winpr2/winpr" TYPE DIRECTORY FILES "D:/GitHub/FreeRDP/winpr/include/winpr/tools" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

