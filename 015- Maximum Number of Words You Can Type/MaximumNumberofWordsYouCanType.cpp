//Problem Link: https://leetcode.com/problems/maximum-number-of-words-you-can-type/description
//Date: 15/09/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        // Store broken letters in a set for O(1) lookup
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());

        int count = 0;  // number of words we can type
        stringstream ss(text);  // split words by spaces
        string word;

        while (ss >> word) {
            bool canType = true;
            for (char c : word) {
                if (broken.count(c)) {
                    canType = false;
                    break;  // stop checking this word
                }
            }
            if (canType) count++;
        }

        return count;
    }
};

// Example usage:
int main() {
    Solution sol;
    cout << sol.canBeTypedWords("hello world", "ad") << endl; // Output: 1
    cout << sol.canBeTypedWords("leet code", "lt") << endl;   // Output: 1
    cout << sol.canBeTypedWords("leet code", "e") << endl;    // Output: 0
    return 0;
}
