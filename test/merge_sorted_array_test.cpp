#include <gtest/gtest.h>
extern "C" {
#include "merge_sorted_array.h"
}

struct TestData {
  std::vector<int> nums1;
  int m;
  std::vector<int> nums2;
  int n;
};

class MergeSortedArrayTest : public ::testing::TestWithParam<TestData> {};

TEST_P(MergeSortedArrayTest, MergeSortedArray) {
  TestData testData = GetParam();
  int *nums1 = testData.nums1.data();
  int m = testData.m;
  int *nums2 = testData.nums2.data();
  int n = testData.n;

  merge(nums1, testData.nums1.size(), m, nums2, testData.nums2.size(), n);
  EXPECT_EQ(std::count_if(testData.nums1.begin(), testData.nums1.end(),
                          [](int x) { return x != 0; }),
            m + n);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCodeTest, MergeSortedArrayTest,
    ::testing::Values(TestData{{1, 2, 3, 0, 0, 0}, 3, {2, 5, 6}, 3},
                      TestData{{4, 5, 6, 0, 0, 0}, 3, {1, 2, 3}, 3},
                      TestData{{1}, 1, {}, 0}, TestData{{0}, 0, {1}, 1}));