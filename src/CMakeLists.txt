include(${CMAKE_SOURCE_DIR}/cmake/scripts/utils.cmake)

# export and install targets
function(export_and_install_targets target_name)
  set(TargetName "")
  snake_2_pascal(${target_name} TargetName)
  export(
    TARGETS ${target_name}
    FILE "${CMAKE_BINARY_DIR}/${TargetName}Targets.cmake"
    NAMESPACE leetcode::)
  install(
    TARGETS ${target_name}
    EXPORT ${TargetName}Targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/leetcode)
  install(
    EXPORT ${TargetName}Targets
    NAMESPACE leetcode::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/leetcode)
endfunction()

add_subdirectory(leetcode)
