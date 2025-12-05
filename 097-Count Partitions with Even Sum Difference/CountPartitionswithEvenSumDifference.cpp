//Problem Link: https://leetcode.com/problems/count-partitions-with-even-sum-difference/description
//Date: 05/12/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }

        int leftSum = 0;
        int count = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            leftSum += nums[i];
            int rightSum = totalSum - leftSum;

            if ((leftSum % 2) == (rightSum % 2)) { // check same parity
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 3, 4, 5, 6};

    int result = sol.countPartitions(nums);
    cout << "Number of valid partitions: " << result << endl;

    return 0;
}
