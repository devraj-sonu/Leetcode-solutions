#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

// for Leetcode solution there is no need to use the above code. Just use the below code.

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = 0;
        int lp = 0;
        int rp = height.size() - 1;

        while (lp < rp) {
            int width = rp - lp;
            int current_height = min(height[lp], height[rp]);
            int current_water = current_height * width;
            max_water = max(max_water, current_water);

            if (height[lp] < height[rp]) {
                lp++;
            } else {
                rp--;
            }
        }

        return max_water;
    }
};
