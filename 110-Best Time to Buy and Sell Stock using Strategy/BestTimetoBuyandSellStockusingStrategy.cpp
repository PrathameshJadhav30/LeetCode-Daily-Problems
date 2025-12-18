// Problem Link:https://leetcode.com/problems/best-time-to-buy-and-sell-stock-using-strategy/description
// Date: 18/12/2025
#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <numeric>
using namespace std;

const int N = 1e5 + 1;
long long sumArr[N];

class Solution {
public:
    static long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        int k2 = k / 2;

        // Prefix sum of strategy[i] * prices[i]
        memset(sumArr, 0, sizeof(long long) * (n + 1));
        for (int i = 0; i < n; i++) {
            sumArr[i + 1] = sumArr[i] + 1LL * strategy[i] * prices[i];
        }

        // Initial modification sum
        long long modify = reduce(prices.begin() + k2, prices.begin() + k, 0LL);

        // Initial profit
        long long profit = max(sumArr[n], modify + sumArr[n] - sumArr[k]);

        // Sliding window optimization
        for (int i = 1; i + k <= n; i++) {
            modify += prices[i + k - 1] - prices[i + k2 - 1];
            profit = max(profit, modify + sumArr[n] - sumArr[i + k] + sumArr[i]);
        }

        return profit;
    }
};

int main() {
    // Example test case
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    vector<int> strategy = {1, -1, 1, -1, 1, -1};
    int k = 4;

    long long result = Solution::maxProfit(prices, strategy, k);
    cout << "Maximum Profit: " << result << endl;

    return 0;
}

