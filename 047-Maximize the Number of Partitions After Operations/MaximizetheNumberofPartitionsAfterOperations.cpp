//Problem Link:https://leetcode.com/problems/maximize-the-number-of-partitions-after-operations/description
//Date:17/10/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string s;
    int k;
    unordered_map<long long, int> memo;

    // Recursive DP with memoization
    int dp(int i, long long mask, bool canChange) {
        if (i == s.size()) return 0;  // Base case

        // Create unique key for memoization
        long long key = ((long long)i << 30) | (mask << 1) | canChange;
        if (memo.count(key)) return memo[key];

        int bit = s[i] - 'a';
        long long newMask = mask | (1LL << bit);
        int res = 0;

        // If unique characters exceed k, start a new partition
        if (__builtin_popcountll(newMask) > k)
            res = 1 + dp(i + 1, 1LL << bit, canChange);
        else
            res = dp(i + 1, newMask, canChange);

        // Try changing one character (if still allowed)
        if (canChange) {
            for (int j = 0; j < 26; ++j) {
                long long changeMask = mask | (1LL << j);
                if (__builtin_popcountll(changeMask) > k)
                    res = max(res, 1 + dp(i + 1, 1LL << j, false));
                else
                    res = max(res, dp(i + 1, changeMask, false));
            }
        }

        return memo[key] = res;
    }

    int maxPartitionsAfterOperations(string s, int k) {
        this->s = s;
        this->k = k;
        memo.clear();
        return dp(0, 0, true) + 1;  // +1 for the final partition
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    string s = "abac";
    int k = 2;

    int ans = sol.maxPartitionsAfterOperations(s, k);
    
    cout << "String: " << s << "\n";
    cout << "K (max unique chars per partition): " << k << "\n";
    cout << "Maximum partitions after operations: " << ans << "\n";

    return 0;
}
