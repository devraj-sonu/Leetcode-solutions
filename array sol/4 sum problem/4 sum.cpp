// bruteforce approach.



#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    for (int l = k + 1; l < n; ++l) {
                        long long sum = 0;
                        sum += (long long)nums[i];
                        sum += (long long)nums[j];
                        sum += (long long)nums[k];
                        sum += (long long)nums[l];

                        if (sum == (long long)target) {
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end()); // sort so set dedupes correctly
                            st.insert(temp);                 // corrected method name
                        }
                    }
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};




// better approach.





#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                unordered_set<long long> hashset;            // faster than set<long long>
                for (int k = j + 1; k < n; ++k) {
                    // --------- FIXED: compute correct 3-sum -----------
                    long long sum3 = (long long)nums[i] + (long long)nums[j] + (long long)nums[k];
                    long long fourth = (long long)target - sum3;
                    // --------------------------------------------------

                    if (hashset.find(fourth) != hashset.end()) {
                        vector<int> temp = { nums[i], nums[j], nums[k], (int)fourth };
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hashset.insert((long long)nums[k]);
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};




// optimal approach.


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>ans;
        for(int i=0; i<n; i++) {
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1; j<n; j++) {
                if(j != i+1 && nums[j] == nums[j-1]) continue;
                int k = j+1;
                int l = n-1;

                while(k<l) {
                    long long sum = (long long)nums[i] + (long long)nums[j]
                                  + (long long)nums[k] + (long long)nums[l];

                    if(sum == target) {
                        vector<int>temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push(temp);
                    }
                    else if(sum>target) {
                        l--;
                    }
                    else{
                        ans.push_back{nums[i],nums[j],nums[k],nums[l]};
                        k++;l--;
                    }              
                }
                    

            }
        }
        return ans;
    }
};



