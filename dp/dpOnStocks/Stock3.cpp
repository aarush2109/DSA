#include <bits/stdc++.h>
using namespace std;

/*
Approach:
This problem allows at most 2 transactions. We use DP where the state
depends on the day, whether we can buy or sell, and the number of
transactions completed. A transaction is counted after selling.
We solve it using both memoization and tabulation.
Time: O(n), Space: O(n).
*/

class Solution {
public:
    // Recursive + Memoization approach
    int f(vector<int> &prices, int i, int buy,
          vector<vector<vector<int>>> &dp, int count) {

        if(count == 2 || i == prices.size()) return 0;
        if(dp[i][buy][count] != -1) return dp[i][buy][count];

        int profit = 0;
        if(buy == 1){
            profit = max(-prices[i] + f(prices, i+1, 0, dp, count),
                         f(prices, i+1, 1, dp, count));
        }
        else{
            profit = max(prices[i] + f(prices, i+1, 1, dp, count+1),
                         f(prices, i+1, 0, dp, count));
        }

        return dp[i][buy][count] = profit;
    }

    // Tabulation approach (your logic preserved)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,
            vector<vector<int>>(2, vector<int>(3, 0)));

        int profit = 0;

        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy < 2; buy++){
                for(int count = 0; count < 2; count++){
                    if(buy == 1){
                        profit = max(-prices[i] + dp[i+1][0][count],
                                     dp[i+1][1][count]);
                    }
                    else{
                        profit = max(prices[i] + dp[i+1][1][count+1],
                                     dp[i+1][0][count]);
                    }
                    dp[i][buy][count] = profit;
                }
            }
        }
        return dp[0][1][0];
    }
};

int main() {
    Solution sol;

    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i = 0; i < n; i++) cin >> prices[i];

    // Tabulation result
    cout << "Maximum Profit (Tabulation): "
         << sol.maxProfit(prices) << endl;

    // Memoization result
    vector<vector<vector<int>>> dp(n,
        vector<vector<int>>(2, vector<int>(2, -1)));

    cout << "Maximum Profit (Memoization): "
         << sol.f(prices, 0, 1, dp, 0) << endl;

    return 0;
}
