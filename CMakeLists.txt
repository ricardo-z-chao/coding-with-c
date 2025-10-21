cmake_minimum_required(VERSION 3.10.0)
project(coding-with-c VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")

include(cmake/scripts/dependencies.cmake)
include(cmake/scripts/format.cmake)

find_package(Uthash REQUIRED)