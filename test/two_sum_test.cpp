#include <vector>

#include <gtest/gtest.h>  // NOLINT(build/include_order)

extern "C" {
#include "two_sum.h"
}

struct TestData {
  std::vector<int> nums;
  int target;
};

class TwoSumTest : public ::testing::TestWithParam<TestData> {};

TEST_P(TwoSumTest, TwoSum) {
  TestData testData = GetParam();
  int* nums = testData.nums.data();
  int target = testData.target;
  int returnSize = 0;
  twoSum(nums, testData.nums.size(), target, &returnSize);
  EXPECT_EQ(2, returnSize);
}

INSTANTIATE_TEST_SUITE_P(LeetCodeTest, TwoSumTest,
                         ::testing::Values(TestData{{2, 7, 11, 15}, 9}, TestData{{3, 2, 4}, 6}, TestData{{3, 3}, 6}));
