#include <bits/stdc++.h>
using namespace std;

/*
Approach:
We convert the number into its binary form and store the bits.
Then we check whether every adjacent bit is different from the previous one.
If any two consecutive bits are the same, the number does not have alternating bits.
Time: O(log n), Space: O(log n).
*/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        vector<int> binary;

        // Convert to binary
        while(n > 0){
            binary.push_back(n % 2);
            n = n / 2;
        }

        int m = binary.size();
        int prev = binary[0];

        // Check alternating property
        for(int i = 1; i < m; i++){
            if(prev == binary[i]) return false;
            else prev = binary[i];
        }
        return true;
    }
};

int main(){
    Solution sol;

    int n;
    cin >> n;

    if(sol.hasAlternatingBits(n))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
