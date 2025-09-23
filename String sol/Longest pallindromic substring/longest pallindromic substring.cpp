#include<string>
#include<cstring>
#include<climits>
using namespace std;


class Solution {
    string expandAroundCenter(const string &s, int left, int right) {
        int n = s.size();
        while(left>=0 && right<n && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right-left-1);
    }
public:
    string longestpalindrome(string s) {
        if(s.empty()) return "";
        string longest = s.substr(0,1);

        for(int i=0; i<s.size(); i++) {
            string p1 = expandAroundCenter(s,i,i);
            if(p1.size() > longest.size()) longest = p1;

            string p2 = expandAroundCenter(s,i,i+1);
            if(p2.size() > longest.size()) longest = p2;
        }
        return longest;
    }
};