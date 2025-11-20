include(${CMAKE_SOURCE_DIR}/cmake/scripts/uthash.cmake)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

find_package(Uthash REQUIRED)

add_library(two_sum two_sum.c)
target_include_directories(
  two_sum INTERFACE "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
                    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/leetcode>")
target_link_libraries(two_sum PRIVATE Uthash)
set_target_properties(two_sum PROPERTIES PUBLIC_HEADER include/two_sum.h)

add_library(merge_sorted_array merge_sorted_array.c)
target_include_directories(
  merge_sorted_array
  INTERFACE "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
            "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>/leetcode>")
set_target_properties(merge_sorted_array
                      PROPERTIES PUBLIC_HEADER include/merge_sorted_array.h)

add_library(three_sum_closest three_sum_closest.c)
target_include_directories(
  three_sum_closest
  INTERFACE "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
            "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>/leetcode>")
set_target_properties(three_sum_closest PROPERTIES PUBLIC_HEADER
                                                   include/three_sum_closest.h)

# define install location of library
set(LIB_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}")

# install and export target
export_and_install_targets(two_sum)
export_and_install_targets(merge_sorted_array)
export_and_install_targets(three_sum_closest)

# install and version config file for the package
configure_package_config_file(
  "${CMAKE_SOURCE_DIR}/config/LeetCodeConfig.cmake.in"
  "${CMAKE_BINARY_DIR}/LeetCodeConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/leetcode
  PATH_VARS LIB_INSTALL_DIR)
write_basic_package_version_file(
  "${CMAKE_BINARY_DIR}/LeetCodeConfigVersion.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY AnyNewerVersion)
install(FILES "${CMAKE_BINARY_DIR}/LeetCodeConfig.cmake"
              "${CMAKE_BINARY_DIR}/LeetCodeConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/leetcode)
