#include "uthash.h"

/**
 * @brief leetcode 1. Two Sum
 * @link https://leetcode.com/problems/two-sum/
 * @param[in] nums input array
 * @param[in] numsSize array size
 * @param[in] target target sum
 * @param[out] returnSize result array size
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
  typedef struct {
    int key;
    int value;
    UT_hash_handle hh;
  } HashTable;
  HashTable* hashTable = NULL;
  for (unsigned int i = 0; i < numsSize; i++) {
    HashTable* entry;
    int key = target - nums[i];
    HASH_FIND_INT(hashTable, &key, entry);
    if (entry != NULL) {
      int* result = (int*)malloc(sizeof(int) * 2);
      result[0] = entry->value;
      result[1] = i;
      *returnSize = 2;
      return result;
    } else {
      HashTable* entry = malloc(sizeof(HashTable));
      entry->key = nums[i];
      entry->value = i;
      HASH_ADD_INT(hashTable, key, entry);
    }
  }
  *returnSize = 0;
  return NULL;
}
