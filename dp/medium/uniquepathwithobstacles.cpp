#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recur(vector<vector<int>>& obstacleGrid, int m, int n,
              vector<vector<int>>& dp) {
        if (m < 0 || n < 0) return 0;

        if (obstacleGrid[m][n] == 1) return 0;

        if (m == 0 && n == 0) return 1;

        if (dp[m][n] != -1)
            return dp[m][n];

        int up = recur(obstacleGrid, m - 1, n, dp);
        int left = recur(obstacleGrid, m, n - 1, dp);

        return dp[m][n] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return recur(obstacleGrid, m - 1, n - 1, dp);
    }
};

int main() {
    Solution sol;

    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    cout << "Obstacle Grid:\n";
    for (auto &row : obstacleGrid) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }

    cout << "Number of unique paths: "
         << sol.uniquePathsWithObstacles(obstacleGrid) << endl;

    return 0;
}
