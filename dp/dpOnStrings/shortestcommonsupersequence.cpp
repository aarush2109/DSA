#include <bits/stdc++.h>
using namespace std;

/*
Approach:
The Shortest Common Supersequence (SCS) is constructed using the Longest
Common Subsequence (LCS) of the two strings.
1) First, compute the LCS length using DP (memoization or tabulation).
2) Then backtrack through the DP table to build the SCS by taking common
   characters once and non-common characters from either string.
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

    // Tabulation + reconstruction approach for SCS
    string shortestCommonSupersequence(string text1, string text2) {
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

        // Backtracking to construct SCS
        string ans = "";
        int i = n, j = m;

        while(i > 0 && j > 0){
            if(text1[i - 1] == text2[j - 1]){
                ans += text1[i - 1];
                i--; j--;
            }
            else if(dp[i - 1][j] > dp[i][j - 1]){
                ans += text1[i - 1];
                i--;
            }
            else{
                ans += text2[j - 1];
                j--;
            }
        }

        while(i > 0){
            ans += text1[i - 1];
            i--;
        }
        while(j > 0){
            ans += text2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    string text1, text2;
    cin >> text1 >> text2;

    // Tabulation + reconstruction result
    cout << "Shortest Common Supersequence: "
         << sol.shortestCommonSupersequence(text1, text2) << endl;

    // Memoization LCS length (for reference)
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    cout << "LCS length (Memoization): "
         << sol.f(n - 1, m - 1, text1, text2, dp) << endl;

    return 0;
}
