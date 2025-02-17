cmake_minimum_required(VERSION 3.12)
cmake_policy(VERSION 3.12)
project(kronos)


#-------------------------------------------------------------------------------
#add local find scripts to CMAKE path
LIST(APPEND CMAKE_MODULE_PATH
    ${CMAKE_CURRENT_SOURCE_DIR}/CMake/Utils
    ${CMAKE_CURRENT_SOURCE_DIR}/CMake/Packages
)

set(YAB_PACKAGE kronos)
set(YAB_VERSION_MAJOR 2)
set(YAB_VERSION_MINOR 6)
set(YAB_VERSION_PATCH 2)

option(YAB_IS_WIP "Is a working package" OFF)
if(YAB_IS_WIP)
  Message(STATUS "Build is a WIP")
  find_package(Git REQUIRED)
  execute_process(COMMAND "${GIT_EXECUTABLE}" rev-parse HEAD OUTPUT_VARIABLE COMMIT_ID OUTPUT_STRIP_TRAILING_WHITESPACE)
  string(SUBSTRING ${COMMIT_ID} 0 9 COMMIT_ID_SHORT)
  set(YAB_VERSION "${YAB_VERSION_MAJOR}.${YAB_VERSION_MINOR}.${YAB_VERSION_PATCH} ${COMMIT_ID_SHORT}")
else()
  set(YAB_VERSION "${YAB_VERSION_MAJOR}.${YAB_VERSION_MINOR}.${YAB_VERSION_PATCH}")
endif()

set(CPACK_SOURCE_GENERATOR TGZ)
set(CPACK_PACKAGE_VERSION_MAJOR ${YAB_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${YAB_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${YAB_VERSION_PATCH})
set(CPACK_PACKAGE_VENDOR "Francois CARON")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/COPYING")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "kronos-${YAB_VERSION}")

set(CPACK_STRIP_FILES YES)
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
set(CPACK_PACKAGE_CONTACT "francois.caron.perso@gmail.com")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Francois CARON")
if (WIN32)
	SET(CPACK_NSIS_INSTALLED_ICON_NAME kronos.exe)
	set(CPACK_NSIS_MENU_LINKS kronos.exe;Kronos)
	set(CPACK_NSIS_URL_INFO_ABOUT "http://www.kronos-emulator.org/")
	set(CPACK_NSIS_COMPRESSOR "/SOLID lzma")
	set(CMAKE_VERBOSE_MAKEFILE ON CACHE BOOL "OFF")
	if(${CMAKE_SIZEOF_VOID_P} EQUAL 8)
		set(CPACK_SYSTEM_NAME "win64")
		set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES64")
		set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "${CPACK_PACKAGE_NAME}${CPACK_PACKAGE_VERSION} (Win64)")
	endif ()
endif ()

include(CPack)

#add_subdirectory(doc)
add_subdirectory(src)
