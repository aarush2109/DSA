/*
Approach:
----------
We need to build a matrix where each cell contains the product of all
elements in the matrix EXCEPT the current cell.

Instead of dividing (which can cause issues with zeros),
we use prefix and suffix products.

Key Idea (based on code logic):
------------------------------
1. Traverse the matrix from start → end:
   - Store product of all previous elements in `prefix[i][j]`

2. Traverse the matrix from end → start:
   - Store product of all next elements in `suffix[i][j]`

3. For each cell:
   - result[i][j] = prefix[i][j] * suffix[i][j]

So effectively:
- prefix[i][j] → product of all elements BEFORE (i,j)
- suffix[i][j] → product of all elements AFTER (i,j)

Multiplying both gives:
👉 product of all elements except current one

NOTE:
- We treat the 2D matrix like a flattened array while traversing

Time Complexity (TC):
---------------------
O(n * m)
- 3 full traversals of the matrix

Space Complexity (SC):
----------------------
O(n * m)
- prefix + suffix + result matrices
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();

        vector<vector<int>> product(n, vector<int>(m, 0));
        vector<vector<long long>> prefix(n, vector<long long>(m, 0));
        vector<vector<long long>> suffix(n, vector<long long>(m, 0));

        long long pre = 1;
        long long suf = 1;

        // Prefix pass (left to right, top to bottom)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefix[i][j] = pre;
                pre = (pre * nums[i][j]) % 12345;
            }
        }

        // Suffix pass (right to left, bottom to top)
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                suffix[i][j] = suf;
                suf = (suf * nums[i][j]) % 12345;
            }
        }

        // Build result
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                product[i][j] = (prefix[i][j] * suffix[i][j]) % 12345;
            }
        }

        return product;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> nums = {
        {1, 2},
        {3, 4}
    };

    vector<vector<int>> result = sol.constructProductMatrix(nums);

    for (auto &row : result) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}