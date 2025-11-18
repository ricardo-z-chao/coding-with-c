cmake_minimum_required(VERSION 3.10.0)
project(coding-with-c VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")

include(cmake/scripts/format_lint.cmake)

format_source()
lint()
format_cmake_file()

include(CTest)

add_subdirectory(src bin)
if(BUILD_TESTING)
  add_subdirectory(test)
endif()

set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_GENERATOR "ZIP")
set(CPACK_SOURCE_GENERATOR "ZIP")
include(CPack)
