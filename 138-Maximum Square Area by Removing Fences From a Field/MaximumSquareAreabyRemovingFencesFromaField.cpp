// Problem Link: https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/description
// Date: 16/01/2026
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <limits>
using namespace std;

class Solution {
public:
    static constexpr int mod = 1e9 + 7;
    vector<int> seen;
    int maxL = 0;

    void findLen(vector<int>& fences, int sz, bool calM) {
        sort(fences.begin(), fences.end());
        for (int l = 0; l < sz - 1; l++) {
            int L = fences[l];
            for (int r = l + 1; r < sz; r++) {
                int Len = fences[r] - L;
                if (calM) {
                    if (Len > maxL && binary_search(seen.begin(), seen.end(), Len))
                        maxL = Len;
                } else {
                    seen.push_back(Len);
                }
            }
        }
    }

    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const int hz = hFences.size() + 2;
        const int vz = vFences.size() + 2;

        if (hz > vz)
            return maximizeSquareArea(n, m, vFences, hFences);

        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        seen.reserve(hz * (hz - 1));
        findLen(hFences, hz, false);

        // Prepare for binary search
        sort(seen.begin(), seen.end());
        seen.erase(unique(seen.begin(), seen.end()), seen.end());

        findLen(vFences, vz, true);

        return (maxL == 0) ? -1 : (long long)maxL * maxL % mod;
    }
};

int main() {
    Solution sol;

    // Example input
    int m = 5, n = 8;
    vector<int> hFences = {2, 4};
    vector<int> vFences = {3, 6};

    int result = sol.maximizeSquareArea(m, n, hFences, vFences);
    cout << "Maximum Square Area: " << result << endl;

    return 0;
}