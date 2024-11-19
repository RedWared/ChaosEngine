cmake_minimum_required(VERSION 3.31.0)
project(ChaosEngine VERSION 0.0.0)
# A = Alpha
# B = Beta
# R = Release
# D = Delta
# Delta version are version unfinishes after first release

set(PROJECT_VERSION_TAG "A")

if (PROJECT_VERSION_TAG STREQUAL "R")
	set(PROJECT_VERSION_STRING "${PROJECT_VERSION}")
else()
	set(PROJECT_VERSION_STRING "${PROJECT_VERSION_TAG}${PROJECT_VERSION}")
endif()

configure_file(
	${CMAKE_CURRENT_LIST_DIR}/version.h.in
	${CMAKE_CURRENT_BINARY_DIR}/version.h
)

find_package(OpenGL REQUIRED)

add_custom_target(ffmpeg
	COMMAND ./configure --prefix=/ --enable-shared --enable-gpl --disable-static --disable-ffplay --disable-ffprobe --disable-ffmpeg --disable-doc --disable-debug
	COMMAND make
	WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/external/FFmpeg
)

add_library(Chaos SHARED
	engine.cpp
	include/Chaos/engine.hpp
	include/Chaos/common.hpp
	logsys/error.cpp
	logsys/log.cpp
)
add_dependencies(Chaos ffmpeg)
target_link_libraries(Chaos
	OpenGL
)

target_include_directories(Chaos PUBLIC
	${CMAKE_CURRENT_LIST_DIR}/include
)
