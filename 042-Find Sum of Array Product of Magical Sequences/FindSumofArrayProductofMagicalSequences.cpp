//Problem Link: https://leetcode.com/problems/find-sum-of-array-product-of-magical-sequences/description
//Date:12/10/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MOD = 1e9 + 7;

    int magicalSum(int m, int k, vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        // Precompute powers of 2 up to nums.length (for fast 2^index calculation)
        vector<long long> pow2(n);
        for (int i = 0; i < n; ++i) pow2[i] = (1LL << i);

        // Generate all sequences of length m (with repetition allowed)
        vector<int> seq(m, 0);
        function<void(int)> dfs = [&](int pos) {
            if (pos == m) {
                // Calculate sum = 2^{seq[0]} + 2^{seq[1]} + ... + 2^{seq[m-1]}
                long long sumBits = 0;
                for (int i = 0; i < m; ++i) sumBits += pow2[seq[i]];

                // Check if number of set bits == k
                if (__builtin_popcountll(sumBits) == k) {
                    // Compute product of nums[seq[i]]
                    long long prod = 1;
                    for (int i = 0; i < m; ++i) {
                        prod = (prod * nums[seq[i]]) % MOD;
                    }
                    ans = (ans + prod) % MOD;
                }
                return;
            }

            for (int i = 0; i < n; ++i) {
                seq[pos] = i;
                dfs(pos + 1);
            }
        };

        dfs(0);
        return ans % MOD;
    }
};

int main() {
    Solution sol;

    // Example 1
    int m1 = 5, k1 = 5;
    vector<int> nums1 = {1, 10, 100, 10000, 1000000};
    cout << sol.magicalSum(m1, k1, nums1) << endl; // Output: 991600007

    // Example 2
    int m2 = 2, k2 = 2;
    vector<int> nums2 = {5, 4, 3, 2, 1};
    cout << sol.magicalSum(m2, k2, nums2) << endl; // Output: 170

    // Example 3
    int m3 = 1, k3 = 1;
    vector<int> nums3 = {28};
    cout << sol.magicalSum(m3, k3, nums3) << endl; // Output: 28

    return 0;
}
