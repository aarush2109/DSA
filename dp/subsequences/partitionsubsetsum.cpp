#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // -------- Recursive + Memoization (Top-Down) --------
    bool f(vector<int> &nums, int target, int i, vector<vector<int>> &dp) {
        if (target == 0) return true;
        if (i == 0) return (nums[i] == target);

        if (dp[i][target] != -1)
            return dp[i][target];

        bool notTake = f(nums, target, i - 1, dp);
        bool take = false;

        if (nums[i] <= target)
            take = f(nums, target - nums[i], i - 1, dp);

        return dp[i][target] = take || notTake;
    }

    // -------- Tabulation (Bottom-Up DP) --------
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for (int x : nums)
            sum += x;

        if (sum % 2 != 0)
            return false;

        int target = sum / 2;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        // Base cases
        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        if (nums[0] <= target)
            dp[0][nums[0]] = true;

        // Fill DP table
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= target; j++) {
                bool notTake = dp[i - 1][j];
                bool take = false;

                if (nums[i] <= j)
                    take = dp[i - 1][j - nums[i]];

                dp[i][j] = take || notTake;
            }
        }
        return dp[n - 1][target];
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 5, 11, 5};

    cout << "Array: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    if (sol.canPartition(nums))
        cout << "Can be partitioned into equal subset sum ✅" << endl;
    else
        cout << "Cannot be partitioned into equal subset sum ❌" << endl;

    return 0;
}
