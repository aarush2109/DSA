#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // -------- Recursive + Memoization (Top-Down) --------
    /*
    int recur(vector<vector<int>> &triangle, int m, int n, vector<vector<int>> &dp) {
        if (m >= triangle.size() || n >= triangle[m].size())
            return 100000;

        if (m == triangle.size() - 1)
            return triangle[m][n];

        if (dp[m][n] != -1)
            return dp[m][n];

        int down = triangle[m][n] + recur(triangle, m + 1, n, dp);
        int right = triangle[m][n] + recur(triangle, m + 1, n + 1, dp);

        return dp[m][n] = min(down, right);
    }
    */

    // -------- Tabulation (Bottom-Up DP) --------
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));

        // Base case: last row
        for (int j = 0; j < m; j++) {
            dp[m - 1][j] = triangle[m - 1][j];
        }

        // Fill DP from bottom to top
        for (int i = m - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                int down = triangle[i][j] + dp[i + 1][j];
                int right = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(down, right);
            }
        }
        return dp[0][0];
    }
};

int main() {
    Solution sol;

    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    cout << "Triangle:\n";
    for (auto &row : triangle) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }

    cout << "Minimum Path Sum: "
         << sol.minimumTotal(triangle) << endl;

    return 0;
}
