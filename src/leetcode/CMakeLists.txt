include(${CMAKE_SOURCE_DIR}/cmake/scripts/uthash.cmake)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

find_package(Uthash REQUIRED)

# Create the two_sum library
add_library(two_sum two_sum.c)
target_include_directories(
  two_sum INTERFACE "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
                    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")
target_link_libraries(two_sum PRIVATE Uthash)
set_target_properties(two_sum PROPERTIES PUBLIC_HEADER include/two_sum.h)

include(CMakePackageConfigHelpers)

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
