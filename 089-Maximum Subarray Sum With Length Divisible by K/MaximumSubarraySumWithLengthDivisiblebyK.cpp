// Problem Link: https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/description
// Date: 27/11/2025
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
    ll maxSubarraySum(vector<int>& nums, int k) {
        ll prefSum = 0;
        ll subMax = LLONG_MIN;

        vector<ll> minSoFar(k, LLONG_MAX / 2);

        // Before adding any element, prefix sum = 0 → index = (k−1) % k
        minSoFar[(k - 1) % k] = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefSum += nums[i];

            // Best subarray ending at i with length % k == 0
            subMax = max(subMax, prefSum - minSoFar[i % k]);

            // Update minimum prefix sum for this modulo position
            minSoFar[i % k] = min(minSoFar[i % k], prefSum);
        }

        return subMax;
    }
};

int main() {
    Solution sol;

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << sol.maxSubarraySum(nums, k) << endl;

    return 0;
}
