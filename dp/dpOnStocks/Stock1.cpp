#include <bits/stdc++.h>
using namespace std;

/*
Approach:
We traverse the array once while keeping track of the minimum price seen so far.
At each step, we calculate the profit if we sell on that day and update the
maximum profit. This ensures we buy at the lowest price before selling.
Time complexity: O(n), Space: O(1).
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = 0;
        int mini = prices[0];

        for(int i = 1; i < n; i++){
            int cost = prices[i] - mini;
            maxi = max(maxi, cost);
            mini = min(mini, prices[i]);
        }
        return maxi;
    }
};

int main() {
    Solution sol;

    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i = 0; i < n; i++) cin >> prices[i];

    cout << "Maximum Profit: " << sol.maxProfit(prices) << endl;

    return 0;
}
