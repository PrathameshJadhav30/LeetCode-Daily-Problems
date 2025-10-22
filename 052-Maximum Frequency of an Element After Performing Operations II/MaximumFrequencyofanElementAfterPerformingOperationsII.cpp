//Problem Link: https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii/description
//Date: 22/10/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int maxFrequency(vector<int>& nums, int k, int numOperations) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = 0, cnt = 0;
        int l = 0, r = 0;

        // Consider nums[i]
        for (int i = 0; i < n; i++) {
            const int x = nums[i];
            const int L = max(1, x - k);
            const int R = min(nums.back(), x + k);

            // Count frequency of current number x
            int f = 1;
            int j = i + 1;
            for (; j < n && nums[j] == x; j++) {
                f++;
            }
            i = j - 1; // nums[j] != x

            // Move l to ensure nums[l] >= L
            while (l < n && nums[l] < L) {
                l++;
            }

            // Move r within range [L, R]
            r = (r > i) ? r : i; // start r from last position
            while (r + 1 < n && nums[r + 1] <= R) {
                r++;
            }

            cnt = r - l + 1;
            ans = max(ans, f + min(cnt - f, numOperations));
        }

        // Consider subintervals with overlapping
        for (l = 0, r = 0; r < n; r++) {
            int x = nums[r];
            int L = max(1, x - 2 * k);
            while (l < r && nums[l] < L) {
                l++;
            }
            ans = max(ans, min(r - l + 1, numOperations));
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 4, 5, 5, 7};
    int k = 2;
    int numOperations = 3;

    int result = Solution::maxFrequency(nums, k, numOperations);
    cout << "Maximum frequency after operations: " << result << endl;

    return 0;
}
