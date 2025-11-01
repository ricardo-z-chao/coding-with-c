include_guard()

include(FetchContent)
FetchContent_Declare(
  Uthash
  GIT_REPOSITORY https://github.com/troydhanson/uthash.git
  GIT_TAG v2.3.0)
FetchContent_MakeAvailable(Uthash)
