/**
 * @brief leetcode 88. Merge Sorted Array
 * @link https://leetcode.com/problems/merge-sorted-array/
 * @param[in,out] nums1 input array1, also is result
 * @param[in] nums1Size array1 size
 * @param[in] m number of elements in the array1
 * @param[in] nums2 input array2
 * @param[in] nums2Size array2 size
 * @param[in] n number of elements in the array2
 */
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
  int i = m - 1, j = n - 1, *k = nums1 + nums1Size - 1;
  while (i >= 0 || j >= 0) {
    if (i < 0) {
      *k-- = nums2[j--];
      continue;
    }
    if (j < 0) {
      return;
    }
    if (nums1[i] <= nums2[j]) {
      *k-- = nums2[j--];
    } else {
      *k-- = nums1[i--];
    }
  }
}
