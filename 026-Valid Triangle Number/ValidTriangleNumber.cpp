//Problem Link: https://leetcode.com/problems/valid-triangle-number/description
//Date: 26/09/2025
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        sort(nums.begin(), nums.end());
        int count = 0;

        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    count += (j - i);
                    j--;
                } else {
                    i++;
                }
            }
        }

        return count;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {2, 2, 3, 4};
    cout << "Output for [2,2,3,4]: " << sol.triangleNumber(nums1) << endl;

    // Test case 2
    vector<int> nums2 = {4, 2, 3, 4};
    cout << "Output for [4,2,3,4]: " << sol.triangleNumber(nums2) << endl;

    // Custom test case
    vector<int> nums3 = {1, 2, 3, 4, 5};
    cout << "Output for [1,2,3,4,5]: " << sol.triangleNumber(nums3) << endl;

    return 0;
}
