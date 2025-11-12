//Problem Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/description
//Date:12/11/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int n = nums.size();
        int res = INT_MAX, cnt1 = 0;

        // Count how many '1's exist in array
        for (int i = 0; i < n; ++i)
            cnt1 += (nums[i] == 1);

        // If there are already 1's, only need to make rest elements equal to 1
        if (cnt1)
            return n - cnt1;

        // Otherwise, find subarray with gcd == 1
        for (int i = 0; i < n; ++i) {
            int g = nums[i];
            for (int j = i + 1; j < n; ++j) {
                g = __gcd(g, nums[j]);
                if (g == 1) {
                    // (j - i) operations to make one element = 1
                    // Then (n - 1) more operations to make all elements 1
                    res = min(res, j - i + n - 1);
                    break;
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 6, 3, 4};

    int result = sol.minOperations(nums);
    cout << "Minimum operations required: " << result << endl;

    return 0;
}
