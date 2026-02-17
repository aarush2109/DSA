#include <bits/stdc++.h>
using namespace std;

/*
Approach:
We use Dynamic Programming where the state depends on the day index,
whether we can buy or sell, and the number of transactions completed.
At each step, we choose to buy, sell, or skip. A transaction is counted
only after a sell. Tabulation fills the DP table from the last day,
and memoization avoids recomputation of overlapping states.
Time: O(n*k), Space: O(n*k).
*/

class Solution {
public:
    // Recursive + Memoization approach
    int f(vector<int> &prices, int i, int buy, int count, int k,
          vector<vector<vector<int>>> &dp) {

        if(i == prices.size() || count == k) return 0;
        if(dp[i][buy][count] != -1) return dp[i][buy][count];

        int profit = 0;
        if(buy == 1){
            profit = max(-prices[i] + f(prices, i+1, 0, count, k, dp),
                         f(prices, i+1, 1, count, k, dp));
        }
        else{
            profit = max(prices[i] + f(prices, i+1, 1, count+1, k, dp),
                         f(prices, i+1, 0, count, k, dp));
        }

        return dp[i][buy][count] = profit;
    }

    // Tabulation approach (your logic preserved)
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,
            vector<vector<int>>(2, vector<int>(k+1, 0)));

        int profit = 0;

        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy < 2; buy++){
                for(int count = 0; count < k; count++){
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

    int n, k;
    cin >> n >> k;
    vector<int> prices(n);
    for(int i = 0; i < n; i++) cin >> prices[i];

    // Tabulation result
    cout << "Maximum Profit (Tabulation): "
         << sol.maxProfit(k, prices) << endl;

    // Memoization result
    vector<vector<vector<int>>> dp(n,
        vector<vector<int>>(2, vector<int>(k, -1)));

    cout << "Maximum Profit (Memoization): "
         << sol.f(prices, 0, 1, 0, k, dp) << endl;

    return 0;
}
