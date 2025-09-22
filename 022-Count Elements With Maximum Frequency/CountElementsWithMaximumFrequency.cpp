//Problem Link : https://leetcode.com/problems/count-elements-with-maximum-frequency
//Date: 22/09/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        
        // Count frequency of each element
        for(int n : nums){
            freq[n]++;
        }

        // Find maximum frequency
        int maxFreq = 0;
        for(auto &p : freq){
            maxFreq = max(maxFreq, p.second);
        }

        // Count how many elements appear with max frequency
        int total = 0;
        for(auto &p : freq){
            if(p.second == maxFreq){
                total += p.second;  // add full frequency
            }
        }

        return total;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1,2,2,3,1,4};
    cout << "Output for [1,2,2,3,1,4]: " 
         << sol.maxFrequencyElements(nums1) << endl;

    // Example 2
    vector<int> nums2 = {1,2,3,4,5};
    cout << "Output for [1,2,3,4,5]: " 
         << sol.maxFrequencyElements(nums2) << endl;

    // Custom test
    vector<int> nums3 = {5,5,5,6,6,7};
    cout << "Output for [5,5,5,6,6,7]: " 
         << sol.maxFrequencyElements(nums3) << endl;

    return 0;
}
