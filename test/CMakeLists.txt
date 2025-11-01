include(${CMAKE_SOURCE_DIR}/cmake/scripts/gtest.cmake)
include(GoogleTest)

add_executable(two_sum_test two_sum_test.cpp)
target_link_libraries(two_sum_test PRIVATE two_sum GTest::gtest_main)
gtest_discover_tests(two_sum_test)

add_executable(merge_sorted_array_test merge_sorted_array_test.cpp)
target_link_libraries(merge_sorted_array_test PRIVATE merge_sorted_array
                                                      GTest::gtest_main)
gtest_discover_tests(merge_sorted_array_test)
