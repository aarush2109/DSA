#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // -------- Recursive + Memoization (Top-Down) --------
    /*
    int recur(vector<int> &nums, int i, vector<int> &dp) {
        if (i == 0) return nums[0];
        if (i < 0) return 0;
        if (dp[i] != -1) return dp[i];

        int picked = nums[i] + recur(nums, i - 2, dp);
        int notpicked = recur(nums, i - 1, dp);

        return dp[i] = max(picked, notpicked);
    }
    */

    // -------- Space Optimized DP (Bottom-Up) --------
    int rob(vector<int>& nums) {
        // int n = nums.size();
        // if (n == 1) return nums[0];
        // vector<int> dp(n, -1);
        // recur(nums, n - 1, dp);
        // return dp[n - 1];

        int n = nums.size();

        int prev1 = nums[0]; // dp[i-1]
        int prev2 = 0;       // dp[i-2]

        for (int i = 1; i < n; i++) {
            int take = nums[i];
            if (i > 1) take += prev2;

            int nottake = prev1;
            int curr = max(take, nottake);

            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 7, 9, 3, 1};

    cout << "House values: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    cout << "Maximum money robbed: "
         << sol.rob(nums) << endl;

    return 0;
}
