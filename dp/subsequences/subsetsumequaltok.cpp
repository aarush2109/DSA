#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int> &arr, int target, int index,
          vector<vector<int>> &dp) {

        if (index == 0) {
            if (target == 0 && arr[0] == 0) return 2;
            if (target == 0 || arr[0] == target) return 1;
            return 0;
        }

        if (dp[index][target] != -1)
            return dp[index][target];

        int nottake = f(arr, target, index - 1, dp);
        int take = 0;

        if (arr[index] <= target)
            take = f(arr, target - arr[index], index - 1, dp);

        return dp[index][target] = take + nottake;
    }

    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return f(arr, target, n - 1, dp);
    }
};

int main() {
    Solution sol;

    vector<int> arr = {2, 3, 5, 6, 8, 10};
    int target = 10;

    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    cout << "Target Sum: " << target << endl;

    cout << "Number of subsets with given sum: "
         << sol.perfectSum(arr, target) << endl;

    return 0;
}
