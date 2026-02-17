#include <bits/stdc++.h>
using namespace std;

/*
Approach:
We use Dynamic Programming where at each day we decide to buy, sell, or skip.
The state depends on the current day and whether we can buy or sell.
When selling, we subtract the transaction fee from the profit.
We solve it using both memoization and tabulation.
Time: O(n), Space: O(n) which can be optimized further.
*/

class Solution {
public:
    // Recursive + Memoization approach
    int f(vector<int> &prices, int i, int buy,
          vector<vector<int>> &dp, int fee){
        if(i == prices.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;
        if(buy == 1){
            profit = max(-prices[i] + f(prices, i+1, 0, dp, fee),
                         f(prices, i+1, 1, dp, fee));
        }
        else{
            // subtract fee when selling
            profit = max(prices[i] + f(prices, i+1, 1, dp, fee) - fee,
                         f(prices, i+1, 0, dp, fee));
        }
        return dp[i][buy] = profit;
    }

    // Tabulation approach (your logic preserved)
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int i = n-1; i >= 0; i--){
            dp[i][1] = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
            dp[i][0] = max(prices[i] + dp[i+1][1] - fee, dp[i+1][0]);
        }
        return dp[0][1];
    }
};

int main(){
    Solution sol;

    int n, fee;
    cin >> n >> fee;
    vector<int> prices(n);
    for(int i = 0; i < n; i++) cin >> prices[i];

    // Tabulation result
    cout << "Maximum Profit (Tabulation): "
         << sol.maxProfit(prices, fee) << endl;

    // Memoization result
    vector<vector<int>> dp(n, vector<int>(2, -1));
    cout << "Maximum Profit (Memoization): "
         << sol.f(prices, 0, 1, dp, fee) << endl;

    return 0;
}
