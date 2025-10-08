//Problem Link: https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description
//Date: 08/10/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int freq[100001] = {0}, pMax = 0;

        // Count frequency of each potion strength and find max potion
        for (int p : potions) {
            freq[p]++;
            pMax = max(pMax, p);
        }

        // Build prefix sum (cumulative frequency)
        partial_sum(freq, freq + pMax + 1, freq);

        const int n = spells.size(), m = potions.size();
        vector<int> result(n, 0);

        for (int i = 0; i < n; i++) {
            const int spell = spells[i];
            // Minimum potion strength needed for success
            const long long k = (success + spell - 1) / spell;

            if (k <= pMax) {
                // Count potions with strength >= k
                result[i] = m - (k >= 1 ? freq[k - 1] : 0);
            }
        }
        return result;
    }
};

int main() {
    vector<int> spells = {5, 1, 3};
    vector<int> potions = {1, 2, 3, 4, 5};
    long long success = 7;

    vector<int> ans = Solution::successfulPairs(spells, potions, success);

    cout << "Successful Pairs for each spell: ";
    for (int val : ans){
      cout << val << " ";
    } 
    cout << endl;

    return 0;
}
