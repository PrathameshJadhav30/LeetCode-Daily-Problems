//Problem Link: https://leetcode.com/problems/largest-perimeter-triangle/description
//Date: 28/09/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // Step 1: Sort the sides in ascending order
        sort(nums.begin(), nums.end());

        // Step 2: Traverse from largest side down to find valid triangle
        for (int i = nums.size() - 1; i >= 2; i--) {
            // Triangle condition: sum of smaller two sides > largest side
            if (nums[i - 2] + nums[i - 1] > nums[i]) {
                return nums[i] + nums[i - 1] + nums[i - 2];
            }
        }
        // Step 3: No valid triangle found
        return 0;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {2, 1, 2};
    cout << "Input: [2,1,2]\n";
    cout << "Output: " << sol.largestPerimeter(nums1) << "\n\n";

    // Example 2
    vector<int> nums2 = {1, 2, 1, 10};
    cout << "Input: [1,2,1,10]\n";
    cout << "Output: " << sol.largestPerimeter(nums2) << "\n\n";

    // Extra test case
    vector<int> nums3 = {3, 6, 2, 3};
    cout << "Input: [3,6,2,3]\n";
    cout << "Output: " << sol.largestPerimeter(nums3) << "\n";

    return 0;
}
