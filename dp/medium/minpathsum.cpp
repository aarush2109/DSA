#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // -------- Recursive + Memoization (Top-Down) --------
    /*
    int recur(vector<vector<int>> &matrix, int m, int n, vector<vector<int>> &dp) {
        if (n < 0 || n >= matrix.size()) return 100000;
        if (m == 0) return matrix[m][n];
        if (dp[m][n] != -1) return dp[m][n];

        int up = matrix[m][n] + recur(matrix, m - 1, n, dp);
        int left = matrix[m][n] + recur(matrix, m - 1, n - 1, dp);
        int right = matrix[m][n] + recur(matrix, m - 1, n + 1, dp);

        return dp[m][n] = min({up, left, right});
    }
    */

    // -------- Tabulation (Bottom-Up DP) --------
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // Base case: first row
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        // Fill DP table
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int up = matrix[i][j] + dp[i - 1][j];
                int left = (j - 1 >= 0) ? matrix[i][j] + dp[i - 1][j - 1] : 1000000;
                int right = (j + 1 < n) ? matrix[i][j] + dp[i - 1][j + 1] : 1000000;

                dp[i][j] = min({up, left, right});
            }
        }

        // Answer is minimum in last row
        int mini = dp[n - 1][0];
        for (int j = 1; j < n; j++) {
            mini = min(mini, dp[n - 1][j]);
        }
        return mini;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };

    cout << "Matrix:\n";
    for (auto &row : matrix) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }

    cout << "Minimum Falling Path Sum: "
         << sol.minFallingPathSum(matrix) << endl;

    return 0;
}
