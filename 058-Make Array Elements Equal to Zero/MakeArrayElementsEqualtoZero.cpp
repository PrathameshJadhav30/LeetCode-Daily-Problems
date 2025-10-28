//Problem Link: https://leetcode.com/problems/make-array-elements-equal-to-zero/description
// Date:28/10/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int len = nums.size();
        int count = 0;
        int left = 0;
        int right = 0;

        // Calculate total sum for 'right'
        for (int v : nums) {
            right += v;
        }

        // Traverse the array
        for (int i = 0; i < len; i++) {
            left += nums[i];
            right -= nums[i];

            // Skip non-zero elements
            if (nums[i] != 0) {
                continue;
            }

            // When both sides equal
            if (left == right) {
                count += 2;
            }

            // When difference is 1
            if (abs(left - right) == 1) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 0, 1, 0, 1}; 
    cout << "Count of valid selections: " << sol.countValidSelections(nums) << endl;
    return 0;
}
