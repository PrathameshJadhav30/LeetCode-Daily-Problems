//Problem Link: https://leetcode.com/problems/sort-vowels-in-a-string/description
//Date: 11/09/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        // Step 1: Collect all vowels
        string vowels;
        auto isVowel = [](char ch) {
            ch = tolower(ch);
            return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
        };

        for (char c : s) {
            if (isVowel(c)) {
                vowels.push_back(c);
            }
        }

        // Step 2: Sort vowels by ASCII value
        sort(vowels.begin(), vowels.end());

        // Step 3: Replace vowels in order
        int idx = 0;
        for (char &c : s) {
            if (isVowel(c)) {
                c = vowels[idx++];
            }
        }

        return s;
    }
};

int main() {
    Solution sol;
    cout << sol.sortVowels("lEetcOde") << endl; // Output: "lEOtcede"
    cout << sol.sortVowels("lYmpH") << endl;    // Output: "lYmpH"
}
