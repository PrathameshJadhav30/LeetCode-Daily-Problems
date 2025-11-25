//Problem Link:https://leetcode.com/problems/smallest-integer-divisible-by-k/description
// Date: 25/11/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) return -1;

        int rem = 1 % k;
        int len = 1;

        while (rem > 0) {
            rem = (rem * 10 + 1) % k;
            len++;
            if (len > k) return -1;
        }
        return len;
    }
};

int main() {
    Solution sol;

    int k = 7;

    int ans = sol.smallestRepunitDivByK(k);

    cout << ans << endl;

    return 0;
}
