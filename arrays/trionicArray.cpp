#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 1;

        if (n < 4) return false;

        // First increasing part
        if (i < n && nums[i] > nums[i - 1]) {
            while (i < n && nums[i] > nums[i - 1]) i++;
        } else return false;

        // Then decreasing part
        if (i < n && nums[i] < nums[i - 1]) {
            while (i < n && nums[i] < nums[i - 1]) i++;
        } else return false;

        // Then increasing again
        if (i < n && nums[i] > nums[i - 1]) {
            while (i < n && nums[i] > nums[i - 1]) i++;
        } else return false;

        return i == n;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 3, 5, 4, 2, 6, 8};
    vector<int> nums2 = {1, 2, 3, 4, 5};
    vector<int> nums3 = {5, 3, 1, 2, 4};

    cout << "Array 1: ";
    for (int x : nums1) cout << x << " ";
    cout << "\nIs Trionic? "
         << (sol.isTrionic(nums1) ? "Yes" : "No") << endl;

    cout << "\nArray 2: ";
    for (int x : nums2) cout << x << " ";
    cout << "\nIs Trionic? "
         << (sol.isTrionic(nums2) ? "Yes" : "No") << endl;

    cout << "\nArray 3: ";
    for (int x : nums3) cout << x << " ";
    cout << "\nIs Trionic? "
         << (sol.isTrionic(nums3) ? "Yes" : "No") << endl;

    return 0;
}
