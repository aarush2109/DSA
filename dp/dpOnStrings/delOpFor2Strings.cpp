#include <bits/stdc++.h>
using namespace std;

/*
Approach:
To make two strings equal using minimum deletions, we find their
Longest Common Subsequence (LCS). Characters that are not part of the LCS
must be deleted from both strings. Thus, total deletions =
(length of word1 - LCS) + (length of word2 - LCS).
LCS is computed using both memoization and tabulation.
*/

class Solution {
public:
    // Recursive + Memoization approach for LCS
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j])
            return dp[i][j] = 1 + f(i - 1, j - 1, s1, s2, dp);

        return dp[i][j] = max(
            f(i - 1, j, s1, s2, dp),
            f(i, j - 1, s1, s2, dp)
        );
    }

    // Tabulation approach for LCS
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

    // Minimum deletions to make two strings equal
    int minDistance(string word1, string word2) {
        int lcs = longestCommonSubsequence(word1, word2);
        return (word1.length() - lcs) + (word2.length() - lcs);
    }
};

int main() {
    Solution sol;
    string word1, word2;
    cin >> word1 >> word2;

    // Tabulation result
    cout << "Minimum Deletions (Tabulation): "
         << sol.minDistance(word1, word2) << endl;

    // Memoization result
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    int lcs = sol.f(n - 1, m - 1, word1, word2, dp);
    cout << "Minimum Deletions (Memoization): "
         << (n - lcs) + (m - lcs) << endl;

    return 0;
}
