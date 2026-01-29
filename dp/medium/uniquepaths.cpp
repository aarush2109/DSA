#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recur(int m, int n, vector<vector<int>> &dp) {
        if (m == 0 && n == 0) return 1;
        if (m < 0 || n < 0) return 0;

        if (dp[m][n] != -1)
            return dp[m][n];

        int up = recur(m - 1, n, dp);
        int left = recur(m, n - 1, dp);

        return dp[m][n] = up + left;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return recur(m - 1, n - 1, dp);
    }
};

int main() {
    Solution sol;

    int m = 3, n = 7;
    cout << "Grid size: " << m << " x " << n << endl;

    cout << "Number of unique paths: "
         << sol.uniquePaths(m, n) << endl;

    return 0;
}
