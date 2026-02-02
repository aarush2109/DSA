#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // -------- Recursive + Memoization (Top-Down) --------
    int f(int i, vector<int> &coins, int amount, vector<vector<int>> &dp) {
        if (i == 0) {
            if (amount % coins[i] == 0) return amount / coins[i];
            else return 100000;
        }
        if (dp[i][amount] != -1) return dp[i][amount];

        int notTake = f(i - 1, coins, amount, dp);
        int take = 1000000;
        if (coins[i] <= amount)
            take = 1 + f(i, coins, amount - coins[i], dp);

        return dp[i][amount] = min(take, notTake);
    }

    // -------- Space Optimized DP (Bottom-Up) --------
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0), cur(amount + 1, 0);

        // Base case for first coin
        for (int T = 0; T <= amount; T++) {
            if (T % coins[0] == 0) prev[T] = T / coins[0];
            else prev[T] = 1000000;
        }

        for (int i = 1; i < n; i++) {
            for (int target = 0; target <= amount; target++) {
                int notTake = prev[target];
                int take = 1000000;
                if (coins[i] <= target)
                    take = 1 + cur[target - coins[i]];

                cur[target] = min(take, notTake);
            }
            prev = cur;
        }

        int ans = prev[amount];
        if (ans >= 100000) return -1;
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << "Coins: ";
    for (int c : coins) cout << c << " ";
    cout << "\nAmount: " << amount << endl;

    cout << "Minimum coins needed: "
         << sol.coinChange(coins, amount) << endl;

    return 0;
}
