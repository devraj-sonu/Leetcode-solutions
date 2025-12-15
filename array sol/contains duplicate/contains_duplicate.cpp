// Using unordered_set – Best Approach.
#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;


class Solution {
public:
    bool containsduplicate(vector<int>& nums) {
        unordered_set<int>seen;

        for(int x:nums) {
            if(seen.count(x)) {
                return true;
            }
            seen.insert(x);
        }
        return false;
    }
    

};



// Alternative (Sorting Approach).

#include<algorithm>


class Solution{
public:
    bool containsduplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == nums[i-1]) {
                return true;
            }
        }
        return false;
    }
};