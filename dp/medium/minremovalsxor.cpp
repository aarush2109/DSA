#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int i, vector<int> &nums, int target, int curr, vector<vector<int>> &dp){
        if(i == nums.size()){
            if(curr == target) return 0;
            return 1e9;
        }

        if(curr < dp[0].size() && dp[i][curr] != -1) return dp[i][curr];

        int take = f(i+1, nums, target, curr ^ nums[i], dp);
        int nottake = 1 + f(i+1, nums, target, curr, dp);

        if(curr < dp[0].size())
            return dp[i][curr] = min(take, nottake);

        return min(take, nottake);
    }

    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();

        // Increased size slightly for safety (still same approach)
        int MAXXOR = 200000;

        vector<vector<int>> dp(n, vector<int>(MAXXOR, -1));

        int ans = f(0, nums, target, 0, dp);

        if(ans == 1e9) return -1;
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 4};
    int target = 4;

    cout << sol.minRemovals(nums, target) << endl;

    return 0;
}