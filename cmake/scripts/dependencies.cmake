include(FetchContent)

# Google Test
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        52eb8108c5bdec04579160ae17225d66034bd723 # release-1.17.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
option(gtest_force_shared_crt "Use shared CRT libraries" ON)
FetchContent_MakeAvailable(googletest)

# Uthash
FetchContent_Declare(
  Uthash
  GIT_REPOSITORY https://github.com/troydhanson/uthash.git
  GIT_TAG        v2.3.0
)
FetchContent_MakeAvailable(Uthash)