#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // --------- Recursive + Memoization (Top-Down) ---------
    /*
    int recur(vector<int> &height, int index, vector<int> &dp) {
        if (index == 0) return 0;

        if (dp[index] != -1)
            return dp[index];

        int left = recur(height, index - 1, dp)
                   + abs(height[index] - height[index - 1]);

        int right = INT_MAX;
        if (index > 1) {
            right = recur(height, index - 2, dp)
                    + abs(height[index] - height[index - 2]);
        }

        return dp[index] = min(left, right);
    }
    */

    // --------- Space Optimized DP (Bottom-Up) ---------
    int minCost(vector<int>& height) {
        int n = height.size();

        int prev1 = 0; // dp[i-1]
        int prev2 = 0; // dp[i-2]

        for (int i = 1; i < n; i++) {
            int fs = prev1 + abs(height[i] - height[i - 1]);
            int ss = INT_MAX;

            if (i > 1)
                ss = prev2 + abs(height[i] - height[i - 2]);

            int curr = min(fs, ss);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main() {
    Solution sol;

    vector<int> height = {10, 20, 30, 10};

    cout << "Heights: ";
    for (int h : height) cout << h << " ";
    cout << endl;

    cout << "Minimum Cost: " << sol.minCost(height) << endl;

    return 0;
}
