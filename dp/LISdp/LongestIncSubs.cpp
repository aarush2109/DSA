#include <bits/stdc++.h>
using namespace std;

/*
Approach:
We use Dynamic Programming where at each index we decide whether to take
the current element in the subsequence or skip it. The state depends on
the current index and the previous chosen index. Memoization avoids
recomputing overlapping states, and tabulation with space optimization
reduces memory by keeping only the next row.
Time: O(n^2), Space: O(n).
*/

class Solution {
public:
    // Recursive + Memoization approach
    int f(vector<int>& nums, int i, int prev, vector<vector<int>> &dp){
        if(i == nums.size()) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];

        int take = 0, nottake = 0;

        if(prev == -1 || nums[i] > nums[prev])
            take = 1 + f(nums, i+1, i, dp);

        nottake = f(nums, i+1, prev, dp);

        return dp[i][prev+1] = max(take, nottake);
    }

    // Tabulation + Space optimized approach (your logic preserved)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n+1, 0), curr(n+1, 0);

        for(int i = n-1; i >= 0; i--){
            for(int prev = i-1; prev >= -1; prev--){
                int take = 0, nottake = 0;

                if(prev == -1 || nums[i] > nums[prev])
                    take = 1 + next[i+1];

                nottake = next[prev+1];

                curr[prev+1] = max(take, nottake);
            }
            next = curr;
        }
        return curr[0];
    }
};

int main(){
    Solution sol;

    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    // Tabulation result
    cout << "LIS Length (Space Optimized): "
         << sol.lengthOfLIS(nums) << endl;

    // Memoization result
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    cout << "LIS Length (Memoization): "
         << sol.f(nums, 0, -1, dp) << endl;

    return 0;
}
