//Problem Link: https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description
// Date: 21/11/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);

        // Record first and last occurrences
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        int ans = 0;

        // For each character from 'a' to 'z'
        for (int c = 0; c < 26; c++) {
            if (first[c] != -1 && last[c] - first[c] > 1) {
                int mask = 0;

                // Collect all distinct characters in between
                for (int i = first[c] + 1; i < last[c]; i++) {
                    mask |= 1 << (s[i] - 'a');
                }

                // Count distinct middle characters
                ans += __builtin_popcount(mask);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    string s = "aabca";

    int result = sol.countPalindromicSubsequence(s);

    cout << "Input: " << s << endl;
    cout << "Count of distinct palindromic subsequences of length 3: " << result << endl;

    return 0;
}
