include_guard()

# find all source files
file(
  GLOB_RECURSE SOURCE_FILES FOLLOW_SYMLINKS
  LIST_DIRECTORIES false
  *.c *.h *.cc *.cpp)
list(FILTER SOURCE_FILES EXCLUDE REGEX ".*/out/.*")

function(format_source)
  find_program(CLANG_FORMAT_PATH clang-format REQUIRED)
  set(PATTERNS)

  add_custom_target(
    format-source ALL
    COMMAND ${CLANG_FORMAT_PATH} -i --verbose ${SOURCE_FILES}
    COMMAND_EXPAND_LISTS
    COMMENT "formatting all source code"
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
endfunction()

function(lint)
  find_program(CPP_LINT cpplint REQUIRED)

  add_custom_target(
    cpplint ALL
    COMMAND ${CPP_LINT} ${SOURCE_FILES}
    COMMAND_EXPAND_LISTS
    COMMENT "running cpplint"
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
endfunction()

function(format_cmake_file)
  find_program(CMAKE_FORMAT_PATH cmake-format REQUIRED)

  file(
    GLOB_RECURSE CMAKE_FILES FOLLOW_SYMLINKS
    LIST_DIRECTORIES false
    CMakeLists.txt ${CMAKE_SOURCE_DIR}/*.cmake)

  list(FILTER CMAKE_FILES EXCLUDE REGEX ".*/out/.*")

  add_custom_target(
    format-cmake-list ALL
    COMMAND ${CMAKE_FORMAT_PATH} -i ${CMAKE_FILES}
    COMMENT "formatting all CMake files"
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
endfunction()
