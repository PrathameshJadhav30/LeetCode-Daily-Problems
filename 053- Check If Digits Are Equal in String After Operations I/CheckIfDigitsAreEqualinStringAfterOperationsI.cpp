//Problem Link: https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/description
//Date: 23/10/2024
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.length() > 2) {
            string newStr;
            for (int i = 0; i < s.length() - 1; i++) {
                int sum = (s[i] - '0' + s[i + 1] - '0') % 10;
                newStr += (sum + '0');
            }
            s = newStr;
        }
        return s[0] == s[1];
    }
};

int main() {
    Solution sol;

    string s = "12345";

    bool result = sol.hasSameDigits(s);

    cout << "Input: " << s << endl;
    if (result)
        cout << " The final two digits are the same." << endl;
    else
        cout << " The final two digits are different." << endl;

    return 0;
}
