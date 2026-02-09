#include <bits/stdc++.h>
using namespace std;

/*
Approach:
We solve the Longest Common Subsequence problem in two ways:
1) Using recursion with memoization, where we compare characters from the end of both strings and store intermediate LCS lengths to avoid recomputation.
2) Using iterative dynamic programming (tabulation), where a 2D table is built to compute the LCS length for all prefixes of the two strings.
*/

class Solution {
public:
    // Recursive + Memoization approach
    int f(int i1, int i2, string &text1, string &text2, vector<vector<int>> &dp){
        if(i1 < 0 || i2 < 0) return 0;
        if(dp[i1][i2] != -1) return dp[i1][i2];

        if(text1[i1] == text2[i2])
            return dp[i1][i2] = 1 + f(i1 - 1, i2 - 1, text1, text2, dp);

        return dp[i1][i2] = max(
            f(i1 - 1, i2, text1, text2, dp),
            f(i1, i2 - 1, text1, text2, dp)
        );
    }

    // Iterative DP (Tabulation) approach
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        for(int j = 0; j <= m; j++) dp[0][j] = 0;
        for(int i = 0; i <= n; i++) dp[i][0] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};

int main() {
    Solution sol;

    string text1, text2;
    cin >> text1 >> text2;

    cout << "LCS length (Tabulation): "
         << sol.longestCommonSubsequence(text1, text2) << endl;

    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    cout << "LCS length (Memoization): "
         << sol.f(n - 1, m - 1, text1, text2, dp) << endl;

    return 0;
}
