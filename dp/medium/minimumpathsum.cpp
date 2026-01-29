#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // -------- Recursive + Memoization (Top-Down) --------
    /*
    int recur(vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp) {
        if (m < 0 || n < 0) return 1000000;
        if (m == 0 && n == 0) return grid[m][n];
        if (dp[m][n] != -1) return dp[m][n];

        int left = grid[m][n] + recur(grid, m, n - 1, dp);
        int up   = grid[m][n] + recur(grid, m - 1, n, dp);

        return dp[m][n] = min(up, left);
    }
    */

    // -------- Tabulation (Bottom-Up DP) --------
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[0][0];
                } else {
                    int up = 10000000;
                    int left = 10000000;

                    if (i > 0) up = grid[i][j] + dp[i - 1][j];
                    if (j > 0) left = grid[i][j] + dp[i][j - 1];

                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    cout << "Grid:\n";
    for (auto &row : grid) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }

    cout << "Minimum Path Sum: "
         << sol.minPathSum(grid) << endl;

    return 0;
}
