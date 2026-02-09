#include <bits/stdc++.h>
using namespace std;

/*
Approach:
To make a string palindrome using minimum insertions, we first find the
Longest Palindromic Subsequence (LPS). The minimum insertions required is
the difference between the string length and the LPS length.
LPS is computed by finding the Longest Common Subsequence (LCS) between
the string and its reverse using both memoization and tabulation.
*/

class Solution {
public:
    // Recursive + Memoization approach for LCS (used to compute LPS)
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

    // Tabulation approach for LPS
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

    // Minimum insertions to make string palindrome
    int minInsertions(string s) {
        return s.length() - longestPalindromeSubseq(s);
    }
};

int main() {
    Solution sol;
    string s;
    cin >> s;

    // Tabulation result
    cout << "Minimum Insertions (Tabulation): "
         << sol.minInsertions(s) << endl;

    // Memoization result
    string rev = s;
    reverse(rev.begin(), rev.end());
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    int lps = sol.f(n - 1, n - 1, s, rev, dp);
    cout << "Minimum Insertions (Memoization): "
         << n - lps << endl;

    return 0;
}
