// Problem Link: https://leetcode.com/problems/count-special-triplets/description
// Date: 09/12/2025
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int mod = 1e9+7;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int M = 100001;
        int n = nums.size();
        int freq[M] = {0}, prev[M] = {0};

        for(int x : nums) 
            freq[x]++;

        long long cnt = 0;
        prev[nums[0]]++;

        for(int i=1; i<n-1; i++){
            int x = nums[i], x2 = x*2;
            if(x2 < M)
                cnt += (long long)prev[x2] * (freq[x2] - prev[x2] - (x==0));
            prev[x]++;
        }
        return cnt % mod;
    }
};

int main() {
    Solution sol;

    // Static Input
    vector<int> nums = {2, 4, 2, 4, 8};

    int result = sol.specialTriplets(nums);
    cout << "Output: " << result << endl;

    return 0;
}
