//Problem Link: https://leetcode.com/problems/vowels-game-in-a-string/description
//Date: 12/09/2025
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        // Check if string contains any vowel
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                return true; // Alice can win
        }
        return false; // No vowels, Alice cannot win
    }
};

int main() {
    Solution solution;

    string test1 = "hello";
    string test2 = "rhythm";
    string test3 = "aeiou";

    cout << "Test 1: " << test1 << " -> Alice wins? " 
         << (solution.doesAliceWin(test1) ? "Yes" : "No") << endl;

    cout << "Test 2: " << test2 << " -> Alice wins? " 
         << (solution.doesAliceWin(test2) ? "Yes" : "No") << endl;

    cout << "Test 3: " << test3 << " -> Alice wins? " 
         << (solution.doesAliceWin(test3) ? "Yes" : "No") << endl;

    // You can also take user input
    string input;
    cout << "Enter a string to check if Alice can win: ";
    cin >> input;
    cout << "Alice wins? " << (solution.doesAliceWin(input) ? "Yes" : "No") << endl;

    return 0;
}
