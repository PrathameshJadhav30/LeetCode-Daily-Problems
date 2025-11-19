//Problem Link:https://leetcode.com/problems/keep-multiplying-found-values-by-two/description
// Date: 19/11/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int k) {
        int bits = 0;

        // Traverse all numbers
        for (auto &n : nums) {
            // Only consider numbers divisible by k
            if (n % k != 0) continue;

            n /= k; // divide by k

            // Check if n is a power of 2 using (n & (n-1)) == 0
            if ((n & (n - 1)) == 0)
                bits |= n;  // set bit for this power of 2
        }

        bits++; // next missing power of 2

        // return k * lowest set bit
        return k * (bits & -bits);
    }
};

int main() {
    vector<int> nums = {2, 4, 6, 8, 16, 32};
    int k = 2;

    Solution obj;
    int ans = obj.findFinalValue(nums, k);

    cout << "Final Value = " << ans << endl;

    return 0;
}
