include_guard()

# snake_case to PascalCase
function(snake_2_pascal snake_case PascalCase)
  string(REPLACE "_" ";" words ${snake_case})
  set(result "")
  foreach(word IN LISTS words)
    if(NOT word STREQUAL "")
      string(SUBSTRING ${word} 0 1 first)
      string(SUBSTRING ${word} 1 -1 rest)
      string(TOUPPER ${first} first_upper)
      string(TOLOWER ${rest} rest_lower)
      string(APPEND result "${first_upper}${rest_lower}")
    endif()
  endforeach()
  set(${PascalCase}
      ${result}
      PARENT_SCOPE)
endfunction()
