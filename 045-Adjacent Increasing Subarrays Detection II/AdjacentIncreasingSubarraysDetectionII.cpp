//Problem Link:https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/description
//Date: 15/10/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int up = 1, preUp = 0, res = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) up++;
            else {
                preUp = up;
                up = 1;
            }
            int half = up >> 1;
            int m = min(preUp, up);
            int candidate = max(half, m);
            if (candidate > res) res = candidate;
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, 2, 3, 1, 2, 3, 4};

    int result = sol.maxIncreasingSubarrays(nums);
    cout << "Maximum length of increasing subarrays: " << result << endl;

    return 0;
}
