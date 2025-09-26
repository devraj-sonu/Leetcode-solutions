#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string convert(string s, int numrows) {
        if(numrows == 1 || numrows>=s.size()) {
            return s;
        }
        vector<string> rows(numrows);
        int going_down = false;
        int curr_row = 0;

        for(char c : s) {
            rows[curr_row] += c;
            if(curr_row == 0 || curr_row == numrows-1) {
                going_down =! going_down;
            }
            curr_row += going_down? 1 : -1;
        }
        string result;
        for(string &row: rows) {
            result += row;
        }
        return result;
    }
};