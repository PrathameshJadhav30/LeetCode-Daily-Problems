//Problem Link: https://leetcode.com/problems/find-triangular-sum-of-an-array/description
//Date: 30/09/2025
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        
        // Repeat until the array has only one element
        while (n > 1) {
            for (int i = 0; i < n - 1; i++) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
            n--; // reduce the effective length
        }
        
        return nums[0];
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};

    Solution sol;
    int result = sol.triangularSum(nums);

    cout << "Triangular sum: " << result << endl;

    return 0;
}
