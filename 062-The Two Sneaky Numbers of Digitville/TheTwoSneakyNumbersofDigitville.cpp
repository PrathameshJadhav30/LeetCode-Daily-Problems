//Problem Link: https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/description
// Date: 31/10/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int XOR = 0;
        int n = nums.size() - 2; // since there are 2 sneaky numbers

        // XOR all numbers in the array
        for (int num : nums)
            XOR ^= num;

        // XOR all numbers from 0 to n-1
        for (int i = 0; i < n; i++)
            XOR ^= i;

        // Find the rightmost set bit (to differentiate the two sneaky numbers)
        int diffBit = XOR & -XOR;

        int a = 0, b = 0;

        // Partition the numbers based on the diffBit
        for (int num : nums) {
            if ((num & diffBit) == 0)
                a ^= num;
            else
                b ^= num;
        }

        // XOR again with numbers from 0 to n-1
        for (int i = 0; i < n; i++) {
            if ((i & diffBit) == 0)
                a ^= i;
            else
                b ^= i;
        }

        return {a, b};
    }
};

int main() {
    Solution sol;

    vector<int> nums = {0, 1, 2, 3, 2, 3}; 
    // Here n = 4, and the sneaky numbers (appearing twice) are 2 and 3.

    vector<int> result = sol.getSneakyNumbers(nums);

    cout << "Sneaky Numbers: ";
    for (int num : result)
        cout << num << " ";
    cout << endl;

    return 0;
}
