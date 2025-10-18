//Problem Link: https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/description
//Date: 18/10/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0, prev = -1e9;

        for (int i = 0; i < nums.size(); i++) {
            int l = max(nums[i] - k, prev + 1);
            if (l <= nums[i] + k) {
                prev = l;
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 3, 5, 7, 9};
    int k = 2;

    int result = sol.maxDistinctElements(nums, k);

    cout << "Input array: ";
    for (int num : nums) cout << num << " ";
    cout << "\nK value: " << k << endl;
    cout << "Maximum number of distinct elements: " << result << endl;

    return 0;
}
