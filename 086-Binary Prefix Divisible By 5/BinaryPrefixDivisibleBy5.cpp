//Problem Link: https://leetcode.com/problems/binary-prefix-divisible-by-5/description
// Date: 24/11/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int val = 0;
        vector<bool> res;

        for (auto& n : nums) {
            val = ((val << 1) + n) % 5;
            res.push_back(val == 0);
        }
        return res;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {0, 1, 1};  
   

    vector<bool> ans = sol.prefixesDivBy5(nums);

    cout << "Input: ";
    for (int x : nums) cout << x << " ";
    cout << "\nOutput: ";

    for (bool x : ans) {
        cout << (x ? "true " : "false ");
    }

    cout << endl;
    return 0;
}
