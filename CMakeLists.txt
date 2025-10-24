cmake_minimum_required(VERSION 3.10.0)
project(coding-with-c VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")

include(${CMAKE_SOURCE_DIR}/cmake/scripts/format.cmake)

format_source(src test)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)