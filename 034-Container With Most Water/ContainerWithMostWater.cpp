//Problem Link: https://leetcode.com/problems/container-with-most-water/description
//Date:4/10/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int lp = 0, rp = height.size() - 1;
        int maxwater = 0;

        while (lp < rp) {
            int width = rp - lp;
            int h = min(height[lp], height[rp]);
            int currentwater = width * h;
            maxwater = max(maxwater, currentwater);

            if (height[lp] < height[rp]) {
                lp++;
            } else {
                rp--;
            }
        }
        return maxwater;
    }
};

int main() {
    // Example input: [1,8,6,2,5,4,8,3,7]
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    Solution sol;
    int result = sol.maxArea(height);

    cout << "Maximum Water Container Area: " << result << endl;

    return 0;
}
