// Problem Link: https://leetcode.com/problems/make-sum-divisible-by-p/description
// Date: 30/11/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long total = 0;
        for (int x : nums) total += x;

        long target = total % p;
        if (target == 0) return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;

        long prefix = 0;
        int res = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            prefix = (prefix + nums[i]) % p;
            int need = (prefix - target + p) % p;

            if (mp.count(need))
                res = min(res, i - mp[need]);

            mp[(int)prefix] = i;
        }

        return res == nums.size() ? -1 : res;
    }
};

int main() {
    vector<int> nums = {3, 1, 4, 2}; 
    int p = 6;

    Solution obj;
    int result = obj.minSubarray(nums, p);

    cout << "Minimum subarray length to remove = " << result << endl;

    return 0;
}
