#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int i = 0;
        int ans = 0;

        for (int j = 0; j < s.size(); j++) {
            freq[s[j]]++;

            while (freq[s[j]] > 1) {
                freq[s[i]]--;
                i++;
            }

            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    string s = "abcabcbb";
    cout << "Input: " << s << endl;
    cout << "Length of longest substring: "
         << sol.lengthOfLongestSubstring(s) << endl;

    return 0;
}
