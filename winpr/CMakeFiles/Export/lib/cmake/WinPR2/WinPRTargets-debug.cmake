#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "winpr" for configuration "Debug"
set_property(TARGET winpr APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(winpr PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/winpr2.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "ntdsapi;C:/OpenSSL-Win32/lib/libssl.lib;C:/OpenSSL-Win32/lib/libcrypto.lib;crypt32;Dbghelp;ws2_32;rpcrt4;credui;Shlwapi"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/winpr2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS winpr )
list(APPEND _IMPORT_CHECK_FILES_FOR_winpr "${_IMPORT_PREFIX}/lib/winpr2.lib" "${_IMPORT_PREFIX}/lib/winpr2.dll" )

# Import target "winpr-tools" for configuration "Debug"
set_property(TARGET winpr-tools APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(winpr-tools PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/winpr-tools2.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "winpr"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG ""
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/winpr-tools2.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS winpr-tools )
list(APPEND _IMPORT_CHECK_FILES_FOR_winpr-tools "${_IMPORT_PREFIX}/lib/winpr-tools2.lib" "${_IMPORT_PREFIX}/lib/winpr-tools2.dll" )

# Import target "winpr-makecert" for configuration "Debug"
set_property(TARGET winpr-makecert APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(winpr-makecert PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/winpr-makecert.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS winpr-makecert )
list(APPEND _IMPORT_CHECK_FILES_FOR_winpr-makecert "${_IMPORT_PREFIX}/bin/winpr-makecert.exe" )

# Import target "winpr-hash" for configuration "Debug"
set_property(TARGET winpr-hash APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(winpr-hash PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/winpr-hash.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS winpr-hash )
list(APPEND _IMPORT_CHECK_FILES_FOR_winpr-hash "${_IMPORT_PREFIX}/bin/winpr-hash.exe" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
