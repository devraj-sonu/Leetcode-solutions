#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        vector<int> val{1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> sym{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        int total = 0;
        for (int i = 0; i < sym.size(); i++) {
            while (s.find(sym[i]) == 0) { // string starts with sym[i]
                total += val[i];
                s = s.substr(sym[i].size());
            }
        }
        return total;
    }
};
