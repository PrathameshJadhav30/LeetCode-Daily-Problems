//Problem Link : https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/description
//Date: 13/09/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        // Frequency map for all characters
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // Define vowels for quick lookup
        unordered_set<char> vowels = {'a','e','i','o','u'};
        
        int maxVowel = 0, maxConsonant = 0;

        // Traverse the frequency map
        for (auto &p : freq) {
            char ch = p.first;
            int count = p.second;

            if (vowels.count(ch)) {
                maxVowel = max(maxVowel, count);
            } else {
                maxConsonant = max(maxConsonant, count);
            }
        }

        return maxVowel + maxConsonant;
    }
};
int main() {
    Solution sol;
    cout << sol.maxFreqSum("successes") << endl; // Output: 6
    cout << sol.maxFreqSum("aeiaeia") << endl;   // Output: 3
    return 0;
}
