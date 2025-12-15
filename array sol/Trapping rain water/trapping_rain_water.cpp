// You are given an array height[] of size n where each element represents the height of a building, and the width of each building is 1 unit.

// When it rains, water can be trapped between the buildings.
// Write a program to calculate the total amount of rainwater that can be trapped between the buildings.

#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int trap(vector<int>& height) {
        int n = height.size();

        if (n==0) {
            return 0;
        }

        vector<int> leftmax(n), rightmax(n);

        leftmax[0] = height[0];
        rightmax[n-1] = height[n-1];

        for(int i=1; i<n; i++) {
            leftmax[i] = max(leftmax[i-1], height[i-1]);
        }

        for(int i=n-2; i>=0; i++) {
            rightmax[i] = max(rightmax[i+1], height[i+1]);
        }

        int watertrapped = 0;

        for(int i=0; i<n; i++) {
            int currwater = min(leftmax[i], rightmax[i]) - height[i];

            if(currwater>0) {
            watertrapped += currwater;
            }
        }

        return watertrapped;

    }
};