//Problem Link: https://leetcode.com/problems/vowel-spellchecker/description
//Date: 14/09/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Utility: check if char is vowel
    bool isVowel(char c) {
        c = tolower(c);
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    
    // Convert word to lowercase
    string toLowerCase(const string &s) {
        string res = s;
        for (auto &ch : res){
         ch = tolower(ch);
        } 
        return res;
    }
    
    // Convert word to "devoweled" lowercase (replace vowels with '*')
    string devowel(const string &s) {
        string res = s;
        for (auto &ch : res) 
        {
            char low = tolower(ch);
            if (isVowel(low)){
               ch = '*';
            } 
            else {
                ch = low;
            }
        }
        return res;
    }
    
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact; // For exact match
        unordered_map<string, string> cap; // lowercase -> first match
        unordered_map<string, string> vow; // devoweled lowercase -> first match
        
        // Preprocess wordlist
        for (string &word : wordlist) 
        {
            exact.insert(word);
            
            string low = toLowerCase(word);

            if (!cap.count(low)){
               cap[low] = word;
            } 
            
            string dev = devowel(word);

            if (!vow.count(dev)){
              vow[dev] = word;
            } 
        }
        
        vector<string> ans;
        for (string &query : queries) 
        {
            if (exact.count(query)) 
            {
                ans.push_back(query); // exact match
            } else 
            {
                string low = toLowerCase(query);
                if (cap.count(low)) 
                {
                    ans.push_back(cap[low]); // case-insensitive match
                } else 
                {
                    string dev = devowel(query);
                    if (vow.count(dev)) 
                    {
                        ans.push_back(vow[dev]); // vowel error match
                    } else 
                    {
                        ans.push_back(""); // no match
                    }
                }
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> wordlist = {"KiTe","kite","hare","Hare"};
    vector<string> queries = {"kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"};
    
    vector<string> res = sol.spellchecker(wordlist, queries);
    
    for (string &s : res) 
    {
        cout << (s.empty() ? "\"\"" : s) << " ";
    }
    cout << endl;
    return 0;
}
