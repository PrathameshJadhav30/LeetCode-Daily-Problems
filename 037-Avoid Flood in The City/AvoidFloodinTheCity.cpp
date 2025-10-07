//Problem Link: https://leetcode.com/problems/avoid-flood-in-the-city/description
//Date: 07/10/2024
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans(rains.size(), 1);   // Initialize all days with 1 (for drying days)
        set<int> st;                        // Store indices of dry days (rains[i] == 0)
        unordered_map<int, int> mp;         // Store last day each lake was filled

        for (int i = 0; i < rains.size(); ++i) {
            if (rains[i] == 0) {
                st.insert(i);               // Keep track of dry days
            } else {
                ans[i] = -1;                // Mark rainy days as -1
                if (mp.count(rains[i])) {   // If lake already filled before
                    auto it = st.lower_bound(mp[rains[i]]);  // Find next dry day after that rain
                    if (it == st.end()) {
                        return {};          // No dry day available → flood unavoidable
                    }
                    ans[*it] = rains[i];    // Dry this lake on that day
                    st.erase(it);           // Remove that dry day
                }
                mp[rains[i]] = i;           // Update the last filled day
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> rains = {1, 2, 0, 0, 2, 1};

    vector<int> result = sol.avoidFlood(rains);

    if (result.empty()) {
        cout << "Flood cannot be avoided!" << endl;
    } else {
        cout << "Result: ";
        for (int x : result) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
