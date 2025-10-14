//Problem Link: https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/description
//Date: 14/10/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), inc = 1, prevInc = 0, maxLen = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) 
                inc++;
            else {
                prevInc = inc;
                inc = 1;
            }
            maxLen = max(maxLen, max(inc >> 1, min(prevInc, inc)));
            if (maxLen >= k) 
                return true;
        }
        return false;
    }
};

int main() {
    Solution obj;
    
    // Example input
    vector<int> nums = {1, 2, 3, 2, 3, 4, 5};
    int k = 2;
    
    // Function call
    bool result = obj.hasIncreasingSubarrays(nums, k);
    
    // Output result
    if (result)
        cout << "True The array has increasing subarrays of length >= " << k << endl;
    else
        cout << "False  No such increasing subarrays found." << endl;

    return 0;
}
