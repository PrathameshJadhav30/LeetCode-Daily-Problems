// Problem Link: https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/description
// Date: 29/11/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long sum = 0;
        for(int x : nums) sum += x;
        return sum % k;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5}; 
    int k = 4;

    Solution obj;
    int result = obj.minOperations(nums, k);

    cout << "Result: " << result << endl;

    return 0;
}
