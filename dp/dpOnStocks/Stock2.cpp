#include <bits/stdc++.h>
using namespace std;

/*
Approach:
We use Dynamic Programming where at each day we decide whether to buy, sell,
or skip. The state depends on the index and whether we are allowed to buy.
Memoization stores overlapping results, and tabulation with space optimization
reduces memory by keeping only next day's values.
Time: O(n), Space: O(1).
*/

class Solution {
public:
    // Recursive + Memoization approach
    int f(vector<int> &prices, int i, int buy, vector<vector<int>> &dp){
        if(i == prices.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;
        if(buy == 1){
            profit = max(-prices[i] + f(prices, i+1, 0, dp),
                         f(prices, i+1, 1, dp));
        }
        else{
            profit = max(prices[i] + f(prices, i+1, 1, dp),
                         f(prices, i+1, 0, dp));
        }
        return dp[i][buy] = profit;
    }

    // Tabulation + Space optimized approach
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;

        int n = prices.size();
        vector<long long> ahead(2, 0), curr(2, 0);

        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                long long profit = 0;
                if(buy == 1){
                    profit = max(-prices[i] + ahead[0], ahead[1]);
                }
                else{
                    profit = max(prices[i] + ahead[1], ahead[0]);
                }
                curr[buy] = profit;
            }
            ahead = curr;
        }
        return ahead[1];
    }
};

int main(){
    Solution sol;

    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i = 0; i < n; i++) cin >> prices[i];

    // Tabulation result
    cout << "Maximum Profit (Space Optimized): "
         << sol.maxProfit(prices) << endl;

    // Memoization result
    vector<vector<int>> dp(n, vector<int>(2, -1));
    cout << "Maximum Profit (Memoization): "
         << sol.f(prices, 0, 1, dp) << endl;

    return 0;
}
