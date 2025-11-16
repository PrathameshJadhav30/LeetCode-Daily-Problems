//Problem Link: https://leetcode.com/problems/number-of-substrings-with-only-1s/description
// Date: 16/11/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSub(string s) {
        long long cnt = 0, total = 0;
        long long mod = 1e9 + 7;

        for (char a : s) {
            if (a == '1') {
                cnt++;
            } else {
                cnt = 0;
            }
            total = (total + cnt) % mod;
        }
        return total;
    }
};

int main() {
    Solution obj;

    string s = "1110011";

    int ans = obj.numSub(s);

    cout << "Binary String: " << s << endl;
    cout << "Number of non-empty substrings of 1s = " << ans << endl;

    return 0;
}
