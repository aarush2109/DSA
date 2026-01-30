#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // -------- Recursive + Memoization (Top-Down) --------
    /*
    bool f(vector<int> &arr, int sum, int i, vector<vector<int>> &dp) {
        if (sum == 0) return true;
        if (i == 0) return (arr[i] == sum);

        if (dp[i][sum] != -1)
            return dp[i][sum];

        bool notTake = f(arr, sum, i - 1, dp);
        bool take = false;

        if (arr[i] <= sum)
            take = f(arr, sum - arr[i], i - 1, dp);

        return dp[i][sum] = take | notTake;
    }
    */

    // -------- Tabulation (Bottom-Up DP) --------
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        // Base case: sum = 0 is always possible
        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        // First element
        if (arr[0] <= sum)
            dp[0][arr[0]] = true;

        // Fill DP table
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= sum; j++) {
                bool nottake = dp[i - 1][j];
                bool take = false;

                if (arr[i] <= j)
                    take = dp[i - 1][j - arr[i]];

                dp[i][j] = take || nottake;
            }
        }
        return dp[n - 1][sum];
    }
};

int main() {
    Solution sol;

    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    cout << "Target Sum: " << sum << endl;

    if (sol.isSubsetSum(arr, sum))
        cout << "Subset with given sum exists ✅" << endl;
    else
        cout << "Subset with given sum does NOT exist ❌" << endl;

    return 0;
}
