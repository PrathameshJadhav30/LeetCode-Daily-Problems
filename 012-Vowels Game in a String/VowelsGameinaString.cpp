//Problem Link: https://leetcode.com/problems/vowels-game-in-a-string/description
//Date: 12/09/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char c) 
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    bool doesAliceWin(string s) {
        int vowelCount = 0;
        for (char c : s) {
            if (isVowel(c))
            {
               vowelCount++;
            } 
        }
        // If no vowels, Alice cannot make a move
        if (vowelCount == 0) {
            return false;
        }

        // If total vowels is odd, Alice can remove all vowels and win
        if (vowelCount % 2 == 1){
          return true;
        } 

        // If total vowels is even, Alice cannot force a win
        return false;
    }
};

int main() {
    Solution sol;
    string s;
    cin >> s;
    if (sol.doesAliceWin(s)){
      cout << "Alice wins\n";
    } 
    else 
    {
        cout << "Bob wins\n";
    }
    return 0;
}
