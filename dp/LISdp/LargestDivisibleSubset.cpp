#include <bits/stdc++.h>
using namespace std;

/*
Approach:
This problem is similar to LIS. We first sort the array so that if nums[i]
is divisible by nums[j], then i > j. We use DP to store the longest divisible
subset ending at each index. A hash array is used to reconstruct the subset
by tracking previous indices.
Time: O(n^2), Space: O(n).
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), hash(n);
        int maxi = 1;
        int last = 0;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            hash[i] = i;
            for(int prev = 0; prev < i; prev++){
                if(nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                last = i;
            }
        }

        // Reconstruct subset
        vector<int> temp;
        temp.push_back(nums[last]);

        while(hash[last] != last){
            last = hash[last];
            temp.push_back(nums[last]);
        }

        reverse(temp.begin(), temp.end());
        return temp;
    }
};

int main(){
    Solution sol;

    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    vector<int> ans = sol.largestDivisibleSubset(nums);

    cout << "Largest Divisible Subset: ";
    for(int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}