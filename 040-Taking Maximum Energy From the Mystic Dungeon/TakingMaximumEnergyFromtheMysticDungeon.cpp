//Problem Link: https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/description
//Date: 10/10/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n);
        int result = INT_MIN;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; --i) {
            // dp[i] = energy[i] + dp[i + k] if next jump exists
            dp[i] = energy[i] + ((i + k < n) ? dp[i + k] : 0);
            result = max(result, dp[i]);
        }
        return result;
    }
};

int main() {
    // Example input
    vector<int> energy = {5, 2, -10, -5, 1};
    int k = 3;

    Solution sol;
    int ans = sol.maximumEnergy(energy, k);
    cout << "Maximum Energy: " << ans << endl;

    return 0;
}
