#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(nums.empty()) return 0;

        int k = 1;
        for(int i=1; i<n; i++) {
            if(nums[i] != nums[i-1]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};