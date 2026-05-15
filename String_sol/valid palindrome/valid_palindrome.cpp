#include<iostream>
#include<string>
using namespace std;

class Solution{
public:
    bool alphaNum(char ch) {
        if((ch>='0' && ch<='9') || (tolower(ch)>='a' && tolower(ch)<='z')) {
            return true;
        }
        return false;
    }
    
    bool isPalindrome(string s) {
        int st = 0;
        int end = s.length()-1;

        while(st<end) {
            if(!alphaNum(s[st])) {
                st++;
                continue;
            }
            if(!alphaNum(s[end])) {
                end--;
                continue;
            }
            if(tolower(s[st])!=tolower(s[end])) {
                return false;
            }
            st++;end--;
        }
        return true;

    }
};


