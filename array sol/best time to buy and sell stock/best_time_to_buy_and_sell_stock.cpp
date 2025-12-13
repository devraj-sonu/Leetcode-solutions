#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
        int maxProfit(vector<int>& prices) {
            int n = prices.size();

            int bestbuy = prices[0];
            int maxprofit = 0;

            for(int i=1; i<n; i++) {
                bestbuy = min(bestbuy, prices[0]);

                int currprofit = prices[i] - bestbuy;

                maxprofit = max(currprofit,maxprofit);
            }
            return maxprofit;
        }

};