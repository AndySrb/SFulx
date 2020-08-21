## Needs windows compilation options
cmake_minimum_required (VERSION 2.6)
if (UNIX)
	set(PROJECTNAME "ResourceLoader")
endif(UNIX)

if (WIN32)
	set(PROJECTNAME "ResourceLoader.exe")
endif (WIN32)
project(${PROJECTNAME})
set(SFMLDIR "SFML")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

if (UNIX)
  set (SFMLDIR "${PROJECT_SOURCE_DIR}/SFML/SFML-linux/")
endif (UNIX)
if (WIN32)
	set (SFMLDIR "${PROJECT_SOURCE_DIR}/SFML/SFML-windows/") ## Folder doesn't exist
endif (WIN32)


# Find SFML
find_package(SFML 2.5 COMPONENTS audio graphics window system REQUIRED)
find_package(Lua 5.3 REQUIRED)
#find_package (OpenGL)

include_directories (${SFML_INCLUDE_DIR})
include_directories (${SFML_LIBRARIES})



include_directories(../../src/)
link_directories(../../src)

aux_source_directory(src/ Sources)
aux_source_directory(../../src/AssetManager Sources)
aux_source_directory(../../src/AssetManager/Lua Sources)




add_executable(bin/${PROJECTNAME} ${Sources} ${SFML_INCLUDE_DIR})

target_link_libraries (bin/${PROJECTNAME} ${SFML_LIBRARIES} -llua -lm -DSFML_STATIC sfml-graphics sfml-window sfml-audio sfml-network sfml-system)
