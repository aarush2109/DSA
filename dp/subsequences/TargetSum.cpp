#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // -------- Recursive + Memoization --------
    int f(int i, vector<int> &arr, int target, vector<vector<int>> &dp) {
        if (i == 0) {
            if (arr[i] == 0 && target == 0) return 2;
            if (target == 0 || target == arr[i]) return 1;
            return 0;
        }

        if (dp[i][target] != -1)
            return dp[i][target];

        int notTake = f(i - 1, arr, target, dp);
        int take = 0;

        if (arr[i] <= target)
            take = f(i - 1, arr, target - arr[i], dp);

        return dp[i][target] = take + notTake;
    }

    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int sum = 0;
        for (int x : arr) sum += x;

        // (S1 - S2 = diff)  =>  S2 = (sum - diff) / 2
        if (sum - diff < 0 || (sum - diff) % 2 != 0)
            return 0;

        int target = (sum - diff) / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return f(n - 1, arr, target, dp);
    }

    int findTargetSumWays(vector<int>& arr, int target) {
        return countPartitions(arr, target);
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    cout << "Array: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    cout << "Target: " << target << endl;

    cout << "Number of ways: "
         << sol.findTargetSumWays(nums, target) << endl;

    return 0;
}
