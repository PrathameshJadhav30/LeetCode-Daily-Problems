//Problem Link: https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/description
// Date: 17/11/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {

        int n = nums.size();
        int pre_index;
        bool f = true;

        for (int i = 0; i < n; i++) {
            if (f && nums[i] == 1) {
                f = false;
                pre_index = i;
                continue;
            }
            if (nums[i] == 1) {
                if (i - pre_index - 1 >= k)
                    pre_index = i;
                else
                    return false;
            }
        }

        return true;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1,0,0,0,1,0,0,1};
    int k = 2;

    bool ans = obj.kLengthApart(nums, k);

    cout << (ans ? "true" : "false") << endl;

    return 0;
}
