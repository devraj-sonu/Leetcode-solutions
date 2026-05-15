#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class solution {
public:
    vector<int>twosum(vector<int>&arr, int tar) {
        unordered_map<int, int>m;
        vector<int>ans;

        for(int i=0; i<arr.size(); i++) {
            int first = arr[i];
            int sec = tar - first;

            if(m.find(sec) != m.end()) {
                ans.push_back(i);
                ans.push_back(m[sec]);
                break;
            }
            m[first] = i;
        }
        return ans;
    }
};




//alternative approacah

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;


class Solution{
public:
    vector<int>twosum(vector<int>&nums, int target) {
        unordered_map<int, int>mp;
        
        for(int i=0; i<nums.size(); i++) {
            int complement = target - nums[i];

            if(mp.find(complement)!=mp.end()) {
                return{mp[complement],i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};