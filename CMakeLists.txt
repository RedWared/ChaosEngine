cmake_minimum_required(VERSION 3.31.0)
project(ChaosEngine VERSION 0.0.1)

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
	${CMAKE_CURRENT_LIST_DIR}/internal/ChaosInfo.hpp.in
	${CMAKE_CURRENT_LIST_DIR}/internal/ChaosInfo.hpp
)

add_library(Chaos SHARED
	include/ChaosEngine/engine.hpp
	engine.cpp
	LogSys/log.cpp
	LogSys/warn.cpp
	LogSys/error.cpp
)
target_include_directories(Chaos PUBLIC
	${CMAKE_CURRENT_LIST_DIR}/include
	${CMAKE_CURRENT_LIST_DIR}/internal
)
