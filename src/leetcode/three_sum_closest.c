#include <stdlib.h>

int compare(const void *, const void *);

/**
 * @brief leetcode 16. 3Sum Closest
 * @link https://leetcode.com/problems/3sum-closest/
 * @param[in] nums input array
 * @param[in] numsSize array size
 * @param[in] target target sum
 * @return closest sum
 */
int threeSumClosest(int *nums, int numsSize, int target) {
  qsort(nums, numsSize, sizeof(int), compare);
  int closest = nums[0] + nums[1] + nums[2];
  int gap = abs(closest - target);
  for (int i = 0; i < numsSize - 2; i++) {
    /* skip duplicates */
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }
    int j = i + 1, k = numsSize - 1;
    while (j < k) {
      int sum = nums[i] + nums[j] + nums[k];
      if (abs(sum - target) < gap) {
        gap = abs(sum - target);
        closest = sum;
      }
      if (sum == target) {
        return sum;
      }
      if (sum < target) {
        j++;
        /* skip duplicates */
        while (j < k && nums[j - 1] == nums[j]) {
          j++;
        }
      } else {
        k--;
        /* skip duplicates */
        while (j < k && nums[k] == nums[k + 1]) {
          k--;
        }
      }
    }
  }
  return closest;
}

/**
 * @brief comparison function for qsort
 * @param[in] a first element
 * @param[in] b second element
 * @return negative if a < b, zero if a == b, positive if a > b
 */
int compare(const void *a, const void *b) { return *(int *)a - *(int *)b; }
