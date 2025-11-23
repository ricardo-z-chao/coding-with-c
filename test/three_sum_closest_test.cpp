#include <vector>

#include <gtest/gtest.h>  // NOLINT(build/include_order)

extern "C" {
#include "three_sum_closest.h"
}

struct TestData {
  std::vector<int> nums;
  int target;
  int result;
};

class ThreeSumClosestTest : public ::testing::TestWithParam<TestData> {};

TEST_P(ThreeSumClosestTest, ThreeSumClosest) {
  TestData testData = GetParam();
  int* nums = testData.nums.data();
  int target = testData.target;
  int result = testData.result;
  int closest = threeSumClosest(nums, testData.nums.size(), target);
  EXPECT_EQ(closest, result);
}

INSTANTIATE_TEST_SUITE_P(LeetCodeTest, ThreeSumClosestTest,
                         ::testing::Values(TestData{{-1, 2, 1, -4}, 1, 2}, TestData{{0, 0, 0}, 1, 0}));
