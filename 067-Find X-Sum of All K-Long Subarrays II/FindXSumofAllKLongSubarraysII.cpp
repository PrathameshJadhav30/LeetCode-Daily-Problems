// Problem Link: https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-ii/description
// Date: 05/11/2025
#include <bits/stdc++.h>
using namespace std;

struct Comp {
    bool operator()(const pair<long long, long long>& a, const pair<long long, long long>& b) const {
        if (a.first != b.first) return a.first > b.first; // higher frequency first
        return a.second > b.second; // if equal, larger value first
    }
};

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<long long, long long> freq;
        multiset<pair<long long, long long>, Comp> top, rest;
        long long topSum = 0;
        vector<long long> ans;

        auto add = [&](long long val) {
            long long oldFreq = freq[val];
            long long newFreq = ++freq[val];

            if (oldFreq > 0) {
                auto it = top.find({oldFreq, val});
                if (it != top.end()) {
                    top.erase(it);
                    topSum -= val * oldFreq;
                } else {
                    rest.erase(rest.find({oldFreq, val}));
                }
            }

            // Decide where to place new frequency
            top.insert({newFreq, val});
            topSum += val * newFreq;

            // Rebalance sets if top has more than x
            if ((int)top.size() > x) {
                auto it = prev(top.end());
                rest.insert(*it);
                topSum -= it->second * it->first;
                top.erase(it);
            }
        };

        auto remove = [&](long long val) {
            long long oldFreq = freq[val];
            long long newFreq = --freq[val];

            if (oldFreq == 0) return;

            auto it = top.find({oldFreq, val});
            if (it != top.end()) {
                top.erase(it);
                topSum -= val * oldFreq;
            } else {
                rest.erase(rest.find({oldFreq, val}));
            }

            if (newFreq > 0) {
                top.insert({newFreq, val});
                topSum += val * newFreq;
            }

            if ((int)top.size() > x) {
                auto it = prev(top.end());
                rest.insert(*it);
                topSum -= it->second * it->first;
                top.erase(it);
            }

            while ((int)top.size() < x && !rest.empty()) {
                auto it = rest.begin();
                top.insert(*it);
                topSum += it->second * it->first;
                rest.erase(it);
            }
        };

        for (int i = 0; i < k; ++i) add(nums[i]);
        ans.push_back(topSum);

        for (int i = k; i < n; ++i) {
            remove(nums[i - k]);
            add(nums[i]);
            ans.push_back(topSum);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 2, 3, 4, 2, 3};
    int k = 6, x = 2;

    vector<long long> result = sol.findXSum(nums, k, x);

    cout << "Output: [";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";
    }
    cout << "]\n";

    return 0;
}
