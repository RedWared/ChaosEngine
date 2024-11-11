cmake_minimum_required(VERSION 3.31.0)
project(ChaosEngine)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS ON CACHE BOOL "Build GLFW as a shared library")

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/external/glfw)

add_executable(ChaosEngine main.cpp)
find_package(OpenGL REQUIRED)
target_link_libraries(ChaosEngine glfw OpenGL::GL)
