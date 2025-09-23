class Solution:
    def expandAroundCenter(self, s:str, left:int, right:int)->str:
        n = s.size()
        while left>=0 and right<n and s[left] == s[right]:
            lp -= 1
            rp += 1
        return s[left + 1:right]
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return ""
        longest = s[0]

        for i in range(len(s)):
            p1 = self.expandAroundCenter(s,i,i)
            if len(p1)>len(longest):
                longest = p1
            p2 = self.expandAroundCenter(s,i,i+1)
            if len(p2)>len(longest):
                longest = p2

        return longest