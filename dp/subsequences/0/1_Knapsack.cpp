#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // -------- Recursive + Memoization --------
    int f(int i, int W, vector<int> &val, vector<int> &wt,
          vector<vector<int>> &dp) {

        if (i == 0) {
            if (wt[i] <= W)
                return val[0];
            else
                return 0;
        }

        if (dp[i][W] != -1)
            return dp[i][W];

        int notTake = f(i - 1, W, val, wt, dp);
        int take = 0;

        if (wt[i] <= W)
            take = val[i] + f(i - 1, W - wt[i], val, wt, dp);

        return dp[i][W] = max(take, notTake);
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return f(n - 1, W, val, wt, dp);
    }
};

int main() {
    Solution sol;

    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;

    cout << "Values: ";
    for (int x : val) cout << x << " ";
    cout << endl;

    cout << "Weights: ";
    for (int x : wt) cout << x << " ";
    cout << endl;

    cout << "Capacity: " << W << endl;

    cout << "Maximum value in Knapsack: "
         << sol.knapsack(W, val, wt) << endl;

    return 0;
}
