function(format_source)
  find_program(CLANG_FORMAT_PATH clang-format REQUIRED)
  set(PATTERNS)

  foreach(item ${ARGN})
    set(EXTENSION h c cc cpp)
    list(TRANSFORM EXTENSION PREPEND "${item}/*.")
    list(APPEND PATTERNS ${EXTENSION})
  endforeach()

  file(
    GLOB_RECURSE SOURCE_FILES FOLLOW_SYMLINKS
    LIST_DIRECTORIES false
    ${PATTERNS})

  add_custom_target(
    format-source ALL
    COMMAND ${CLANG_FORMAT_PATH} -i --verbose --style=LLVM ${SOURCE_FILES}
    COMMAND_EXPAND_LISTS
    COMMENT "formatting all source code"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endfunction()
