
# Given a string s, find the length of the longest substring without duplicate characters.

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        last = [-1] * 256   # last seen index for ASCII chars
        left = 0
        maxLen = 0

        for right, ch in enumerate(s):
            c = ord(ch)     # convert char to ASCII index
            if last[c] >= left:
                # duplicate found, move left pointer
                left = last[c] + 1
            last[c] = right  # update last seen index
            maxLen = max(maxLen, right - left + 1)

        return maxLen
