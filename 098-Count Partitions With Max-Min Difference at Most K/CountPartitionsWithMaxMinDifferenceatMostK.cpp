// Problem Link: https://leetcode.com/problems/count-partitions-with-max-min-difference-at-most-k/description
// Date: 06/12/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int mod = 1e9 + 7;
        int n = nums.size();
        
        // P[r] will store the left boundary of valid segment ending at r
        vector<int> P(n);
        multiset<int> S;

        int l = 0;
        for(int r = 0; r < n; r++){
            S.insert(nums[r]);

            // Maintain valid window where max-min <= k
            while(*S.rbegin() - *S.begin() > k){
                S.erase(S.find(nums[l]));
                l++;
            }
            P[r] = l;
        }

        // DP + Prefix sum
        vector<int> dp(n + 1), psum(n + 1);
        dp[0] = psum[0] = 1;

        for(int r = 0; r < n; r++){
            int L = P[r];

            long long valid = psum[r];
            if(L > 0) valid = (valid - psum[L - 1] + mod) % mod;

            dp[r + 1] = valid % mod;
            psum[r + 1] = (psum[r] + dp[r + 1]) % mod;
        }

        return dp[n];
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 3, 5, 6};
    int k = 3;

    cout << "Number of valid partitions: " << sol.countPartitions(nums, k) << endl;

    return 0;
}
