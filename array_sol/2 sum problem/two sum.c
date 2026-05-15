#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10007   // a big prime number for hash table size

// Each entry stores one number and its index
typedef struct {
    int key;   // the number (nums[i])
    int val;   // the index i
    int used;  // flag: 0 = empty, 1 = filled
} Entry;

// Simple hash function (handles negative numbers too)
int hash(int key) {
    if (key < 0) key = -key;
    return key % TABLE_SIZE;
}

// Main LeetCode function
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;                            // always return 2 indices
    int* result = (int*)malloc(2 * sizeof(int));
    Entry table[TABLE_SIZE] = {0};              // hash table initialized to empty

    // Loop over all numbers
    for (int i = 0; i < numsSize; i++) {
        int need = target - nums[i];            // we want to find this number
        int h = hash(need);

        // 🔹 Step 1: Search if "need" already exists in table
        while (table[h].used) {                 // slot already filled
            if (table[h].key == need) {         // found the number we need
                result[0] = table[h].val;       // index of "need"
                result[1] = i;                  // current index
                return result;                  // solution found
            }
            h = (h + 1) % TABLE_SIZE;           // linear probing (go to next slot)
        }

        // 🔹 Step 2: Insert current number nums[i] into the table
        h = hash(nums[i]);
        while (table[h].used)                   // if slot occupied, find next
            h = (h + 1) % TABLE_SIZE;

        table[h].key = nums[i];                 // store number
        table[h].val = i;                       // store index
        table[h].used = 1;                      // mark slot as used
    }

    *returnSize = 0;                            // no answer (not possible in LeetCode)
    return NULL;
}
