#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int mini = INT_MAX;
        for (int i = 0; i < arr.size() - 1; i++) {
            int diff = abs(arr[i + 1] - arr[i]);
            mini = min(mini, diff);
        }

        vector<vector<int>> ans;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] == mini) {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {4, 2, 1, 3};

    cout << "Input array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    vector<vector<int>> result = sol.minimumAbsDifference(arr);

    cout << "Pairs with minimum absolute difference:\n";
    for (auto &p : result) {
        cout << "[" << p[0] << ", " << p[1] << "]" << endl;
    }

    return 0;
}
