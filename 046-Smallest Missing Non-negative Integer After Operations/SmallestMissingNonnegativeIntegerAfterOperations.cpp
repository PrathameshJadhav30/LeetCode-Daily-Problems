//Problem Link: https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/description
//Date: 16/10/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int v) {
        long long n = nums.size(), x, res = 0;
        vector<int> rem(v, 0);

        // Count occurrences of each remainder when divided by v
        for (int i = 0; i < n; i++) {
            x = ((nums[i] % v) + v) % v; // handle negative numbers correctly
            rem[x]++;
        }

        // Increment res while remainders exist in order
        while (rem[res % v]--) res++;

        return res;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, -10, 7, 13, 6, 8};
    int v = 5;

    int result = sol.findSmallestInteger(nums, v);

    cout << "Smallest missing integer: " << result << endl;

    return 0;
}
