#include<iostream>
#include<string>
#include<climits>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        int sign = 1;
        long long num = 0;

        while(i < n && s[i] == ' ') i++;

        if(i<n && s[i] == '+' || s[i] == '-') {
            if(s[i]=='-') sign = -1;
            i++;
        }

        while(i<n && isdigit(s[i])) {
            int digit = s[i] - '0';
            num = num*10+digit;

            if(sign*num>INT_MAX) return INT_MAX;
            if(sign*num<INT_MIN) return INT_MIN;

            i++;
        }

        return sign*num;
    }
};


// most optimal approach of the code.



class Solution {
public:
    int myAtoi(string s) {
        if(s.length() == 0) return 0;

        int i = 0;
        while(i<s.size() && s[i] == ' ') i++;
        s = s.substr(i);

        int sign = +1;
        long long ans = 0;

        if(s[0] == '-') sign= -1;

        int MAX = INT_MAX, MIN = INT_MIN;
        i=(s[0] == '+' || s[0] == '-')? 1 : 0;

        while(i<s.length()) {
            if(s[0] == ' ' || !isdigit(s[i])) break;

            ans = ans*10 + s[i] - '0';
            if(sign == -1 && -1*ans<MIN) return MIN;
            if(sign == 1 && ans>MAX) return MAX;

            i++;
        }
        return (int)(sign*ans);
    }
};