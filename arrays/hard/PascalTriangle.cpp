/*
Approach:
----------
We generate Pascal’s Triangle row by row.
- Start with 1 for every row
- Each next element is calculated using the previous one:
    next = previous * (row - i) / i
- This avoids factorial calculations and builds the row efficiently

Example:
Row 5 → 1 4 6 4 1

Time Complexity (TC):
---------------------
O(numRows^2)
- We generate each row up to numRows
- Each row takes O(row) time

Space Complexity (SC):
----------------------
O(numRows^2)
- To store the full Pascal’s Triangle
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> generateRow(int row) {
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);

        for (int i = 1; i < row; i++) {
            ans = ans * (row - i);
            ans = ans / i;
            ansRow.push_back((int)ans);
        }

        return ansRow;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for (int i = 1; i <= numRows; i++) {
            res.push_back(generateRow(i));
        }

        return res;
    }
};

int main() {
    Solution sol;
    int numRows = 5;

    vector<vector<int>> result = sol.generate(numRows);

    for (auto &row : result) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}