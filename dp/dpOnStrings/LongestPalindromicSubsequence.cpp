#include <bits/stdc++.h>
using namespace std;

/*
Approach:
The Longest Palindromic Subsequence (LPS) problem is solved by reducing it to
Longest Common Subsequence (LCS) between the string and its reverse.
1) Recursive + Memoization: Recursively compare characters from both strings
   while storing results for overlapping subproblems.
2) Tabulation: Build a DP table iteratively to compute LCS length for all prefixes.
*/

class Solution {
public:
    // Recursive + Memoization approach
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

    // Tabulation approach
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string text2 = s;
        reverse(s.begin(), s.end());
        int m = text2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        for(int j = 0; j <= m; j++) dp[0][j] = 0;
        for(int i = 0; i <= n; i++) dp[i][0] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i - 1] == text2[j - 1])
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
    string s;
    cin >> s;

    // Tabulation result
    cout << "LPS length (Tabulation): "
         << sol.longestPalindromeSubseq(s) << endl;

    // Recursive + Memoization result
    string rev = s;
    reverse(rev.begin(), rev.end());
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << "LPS length (Memoization): "
         << sol.f(n - 1, n - 1, s, rev, dp) << endl;

    return 0;
}
