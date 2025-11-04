// Problem Link: https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/description
// Date: 04/11/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i <= n - k; i++) {
            unordered_map<int, int> freq;

            // Count frequencies in current subarray
            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }

            // Store (freq, value) pairs
            vector<pair<int, int>> freqList;
            for (auto& p : freq) {
                freqList.push_back({p.second, p.first});
            }

            // Sort by frequency desc, then value desc
            sort(freqList.begin(), freqList.end(), [&](auto& a, auto& b) {
                if (a.first == b.first)
                    return a.second > b.second;
                return a.first > b.first;
            });

            // Calculate sum of top x elements
            int sum = 0;
            int count = 0;
            for (auto& p : freqList) {
                if (count == x) break;
                sum += p.first * p.second;
                count++;
            }

            ans.push_back(sum);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 1, 2, 2, 3, 4, 2, 3};
    int k = 6, x = 2;

    vector<int> res = sol.findXSum(nums, k, x);
    for (int val : res)
        cout << val << " ";

    cout << endl;
    return 0;
}
