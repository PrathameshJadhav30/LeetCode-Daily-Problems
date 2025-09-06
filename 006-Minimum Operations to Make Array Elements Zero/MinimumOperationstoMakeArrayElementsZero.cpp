//Problem Link: https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/description
// Date: 06/09/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;

        for (auto &q : queries) {
            long long l = q[0], r = q[1];
            long long totalSteps = 0;

            long long step = 1;
            long long low = 1, high = 3;  // numbers in [low..high] need "step" operations

            while (low <= r) {
                long long left = max(l, low);
                long long right = min(r, high);

                if (left <= right) {
                    long long cnt = right - left + 1; 
                    totalSteps += cnt * step;
                }

                step++;
                low *= 4;
                high = high * 4 + 3;
            }

            // ceil(totalSteps / 2)
            ans += (totalSteps + 1) / 2;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<vector<int>> queries1 = {{1, 2}, {2, 4}};
    cout << "Output 1: " << sol.minOperations(queries1) << endl; 
    // Expected: 3

    // Test case 2
    vector<vector<int>> queries2 = {{2, 6}};
    cout << "Output 2: " << sol.minOperations(queries2) << endl; 
    // Expected: 4

    // Test case 3 (custom)
    vector<vector<int>> queries3 = {{1, 10}};
    cout << "Output 3: " << sol.minOperations(queries3) << endl;

    return 0;
}
