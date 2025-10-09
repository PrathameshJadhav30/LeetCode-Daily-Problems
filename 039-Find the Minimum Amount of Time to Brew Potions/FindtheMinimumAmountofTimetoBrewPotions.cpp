//Problem Link: https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions/description
//Date: 09/10/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> done(n + 1, 0);
        
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                done[i + 1] = max(done[i + 1], done[i]) + 1LL * mana[j] * skill[i];
            }
            for (int i = n - 1; i > 0; --i) {
                done[i] = done[i + 1] - 1LL * mana[j] * skill[i];
            }
        }
        
        return done[n];
    }
};

int main() {
    Solution sol;

    vector<int> skill = {3, 1, 2};
    vector<int> mana = {2, 4};

    long long result = sol.minTime(skill, mana);
    cout << "Minimum Time: " << result << endl;

    return 0;
}
