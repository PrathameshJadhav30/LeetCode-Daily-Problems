//Problem Link: https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/description
//Date: 13/10/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<unordered_map<char, int>> freq(words.size());

        // Build frequency maps for each word
        for (int i = 0; i < words.size(); i++) {
            for (char ch : words[i])
                freq[i][ch]++;
        }

        vector<string> ans;
        ans.push_back(words[0]); // always include the first word

        // Compare each word's frequency map with the previous one
        for (int i = 1; i < words.size(); i++) {
            if (freq[i] != freq[i - 1]) // if not anagram
                ans.push_back(words[i]);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    // Example input
    vector<string> words = {"abba", "baba", "bbaa", "cd", "cd"};

    // Function call
    vector<string> result = obj.removeAnagrams(words);

    // Output result
    cout << "Result after removing anagrams:\n";
    for (string &word : result)
        cout << word << " ";
    cout << endl;

    return 0;
}
