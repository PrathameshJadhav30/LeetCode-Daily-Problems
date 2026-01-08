// Problem Link: https://leetcode.com/problems/max-dot-product-of-two-subsequences/description
// Date: 08/01/2026
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> nums1, nums2;
    vector<vector<int>> memo;
    int n, m;
    const int NEG_INF = -1000000000;

    int dp(int i, int j) {
        // If either array is exhausted
        if (i == n || j == m)
            return NEG_INF;

        // If already computed
        if (memo[i][j] != INT_MIN)
            return memo[i][j];

        int take = nums1[i] * nums2[j];

        int res = max({
            take + dp(i + 1, j + 1), // take both and continue
            take,                   // take only this pair
            dp(i + 1, j),            // skip nums1[i]
            dp(i, j + 1)             // skip nums2[j]
        });

        return memo[i][j] = res;
    }

    int maxDotProduct(vector<int>& a, vector<int>& b) {
        nums1 = a;
        nums2 = b;
        n = nums1.size();
        m = nums2.size();

        memo.assign(n, vector<int>(m, INT_MIN));
        return dp(0, 0);
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {2, 1, -2, 5};
    vector<int> nums2 = {3, 0, -6};

    // Function Call
    int result = sol.maxDotProduct(nums1, nums2);

    // Output
    cout << "Maximum Dot Product: " << result << endl;

    return 0;
}

