#include <bits/stdc++.h>
using namespace std;

/*
Approach:
This problem is similar to LIS. We first sort the words based on length.
Then for each word, we check all smaller words to see if one can be formed
by inserting exactly one character. If yes, we update the DP length.
Thus, we build the longest possible chain.
Time: O(n^2 * word length), Space: O(n).
*/

class Solution {
public:
    // Function to check if b is predecessor of a
    bool check(string &a, string &b){
        int i = 0, j = 0;

        if(a.length() - b.length() != 1) return false;

        while(i < a.size()){
            if(j < b.size() && a[i] == b[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }

        return (j == b.size());
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 1;

        // Sort by word length
        sort(words.begin(), words.end(), [](string &a, string &b){
            return a.size() < b.size();
        });

        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(1 + dp[prev] > dp[i] && check(words[i], words[prev])){
                    dp[i] = 1 + dp[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};

int main(){
    Solution sol;

    int n;
    cin >> n;
    vector<string> words(n);
    for(int i = 0; i < n; i++) cin >> words[i];

    cout << "Longest String Chain Length: "
         << sol.longestStrChain(words) << endl;

    return 0;
}