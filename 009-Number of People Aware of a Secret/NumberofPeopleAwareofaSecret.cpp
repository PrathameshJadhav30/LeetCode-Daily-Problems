//Problem Link: https://leetcode.com/problems/number-of-people-aware-of-a-secret/description
//Date: 09/09/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0); // dp[i] = number of people who learn the secret on day i

        dp[1] = 1; // Day 1, one person knows the secret

        for (int i = 1; i <= n; i++) {
            for (int j = i + delay; j < i + forget && j <= n; j++) {
                dp[j] = (dp[j] + dp[i]) % MOD;
            }
        }

        long long ans = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            if (i >= 1) {
                ans = (ans + dp[i]) % MOD;
            }
        }
        return ans;
    }
};
int main() {
    Solution sol;

    // Example 1
    int n1 = 6, delay1 = 2, forget1 = 4;
    cout << "Output 1: " << sol.peopleAwareOfSecret(n1, delay1, forget1) << endl; // Expected: 5

    // Example 2
    int n2 = 4, delay2 = 1, forget2 = 3;
    cout << "Output 2: " << sol.peopleAwareOfSecret(n2, delay2, forget2) << endl; // Expected: 6

    return 0;
}
