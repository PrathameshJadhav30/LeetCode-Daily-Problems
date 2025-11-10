//Problem Link: https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/description
// Date: 10/11/2025
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        nums.push_back(0);               // Add sentinel value
        vector<int> stack;               // Custom stack to simulate process
        int count = 0;                   // Operation count
        
        for (int i = 0; i < nums.size(); i++) {
            while (!stack.empty()) {
                if (nums[i] > stack.back()) {
                    stack.push_back(nums[i]);
                    break;
                } 
                else if (nums[i] < stack.back()) {
                    stack.pop_back();
                    count++;
                } 
                else {
                    break;
                }
            }

            if (stack.empty() && nums[i] != 0) {
                stack.push_back(nums[i]);
            }
        }
        return count;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 2, 1};

    int result = sol.minOperations(nums);

    cout << "Minimum Operations: " << result << endl;

    return 0;
}
