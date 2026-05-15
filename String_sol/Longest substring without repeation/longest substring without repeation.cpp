
// Given a string s, find the length of the longest substring without duplicate characters.

// optimal approach.

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);  // hash array for ASCII chars
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.size(); ++right) {
            unsigned char c = s[right];
            if (last[c] >= left) {
                // duplicate found, shift left
                left = last[c] + 1;
            }
            last[c] = right;  // update last seen index
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
