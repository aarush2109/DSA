#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int maxi = INT_MIN;
        int i = 0, j = n - 1;

        while (i <= j) {
            int sum = nums[i] + nums[j];
            maxi = max(maxi, sum);
            i++;
            j--;
        }
        return maxi;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3, 5, 2, 3};
    cout << "Array: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    cout << "Minimized Maximum Pair Sum: "
         << sol.minPairSum(nums) << endl;

    return 0;
}
