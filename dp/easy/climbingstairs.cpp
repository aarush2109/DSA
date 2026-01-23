#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        int prev1 = 2;
        int prev2 = 1;

        for (int i = 2; i < n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main() {
    Solution sol;

    int n = 5;
    cout << "Number of steps: " << n << endl;
    cout << "Ways to climb: " << sol.climbStairs(n) << endl;

    return 0;
}
