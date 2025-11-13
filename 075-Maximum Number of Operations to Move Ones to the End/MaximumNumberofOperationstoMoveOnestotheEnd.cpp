//Problem Link: https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/description
// Date: 13/11/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(string s) {
        int ones = 0, res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1')
                ones++;
            else if ((i > 0) && s[i - 1] == '1')
                res += ones;
        }
        return res;
    }
};

int main() {
    Solution sol;

    string s = "11010";

    int result = sol.maxOperations(s);
    cout << "Binary string: " << s << endl;
    cout << "Maximum operations: " << result << endl;

    return 0;
}
