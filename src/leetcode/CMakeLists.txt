include(${CMAKE_SOURCE_DIR}/cmake/scripts/uthash.cmake)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

find_package(Uthash REQUIRED)

# Create the two_sum library
add_library(two_sum two_sum.c)
target_include_directories(
  two_sum INTERFACE "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
                    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/leetcode>")
target_link_libraries(two_sum PRIVATE Uthash)
set_target_properties(two_sum PROPERTIES PUBLIC_HEADER include/two_sum.h)

# Create the merge_sorted_arrays library
add_library(merge_sorted_array merge_sorted_array.c)
target_include_directories(
  merge_sorted_array
  INTERFACE "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
            "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>/leetcode>")
set_target_properties(merge_sorted_array
                      PROPERTIES PUBLIC_HEADER include/merge_sorted_array.h)

# define install location of library
set(LIB_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}")

# install export set for the two_sum library
export(
  TARGETS two_sum
  FILE "${CMAKE_BINARY_DIR}/TwoSumTargets.cmake"
  NAMESPACE leetcode::)
install(
  TARGETS two_sum
  EXPORT TwoSumTargets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/leetcode)
install(
  EXPORT TwoSumTargets
  NAMESPACE leetcode::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/leetcode)

# install export set for the merge_sorted_array library
export(
  TARGETS merge_sorted_array
  FILE "${CMAKE_BINARY_DIR}/MergeSortedArrayTargets.cmake"
  NAMESPACE leetcode::)
install(
  TARGETS merge_sorted_array
  EXPORT MergeSortedArrayTargets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/leetcode)
install(
  EXPORT MergeSortedArrayTargets
  NAMESPACE leetcode::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/leetcode)

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
