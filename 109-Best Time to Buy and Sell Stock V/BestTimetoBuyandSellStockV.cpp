// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/description
// Date: 17/12/2025
#include <iostream>
#include <vector>   
#include <climits>
using namespace std;

class Solution 
{
public:
    long long helper(int ind, int n, vector<int>& prices, int k,
                     int canBuy, int type,
                     vector<vector<vector<vector<long long>>>> &dp)
    {
        // Base case
        if (ind == n || k == 0)
        {
            if (canBuy == 1) return 0;
            return -1e9; // invalid state
        }

        int t = type + 1; // type: -1 -> 0, 0 -> 1, 1 -> 2

        if (dp[ind][k][canBuy][t] != LLONG_MIN)
            return dp[ind][k][canBuy][t];

        long long res;

        if (canBuy == 1)
        {
            // Buy normally
            long long buy = -1LL * prices[ind]
                            + helper(ind + 1, n, prices, k, 0, 0, dp);

            // Short sell
            long long shortBuy = 1LL * prices[ind]
                                 + helper(ind + 1, n, prices, k, 0, 1, dp);

            // Skip
            long long skip = helper(ind + 1, n, prices, k, 1, -1, dp);

            res = max({buy, shortBuy, skip});
        }
        else
        {
            long long sell = LLONG_MIN;

            // Normal sell
            if (type == 0)
                sell = 1LL * prices[ind]
                       + helper(ind + 1, n, prices, k - 1, 1, -1, dp);

            // Buy back after short sell
            else if (type == 1)
                sell = -1LL * prices[ind]
                       + helper(ind + 1, n, prices, k - 1, 1, -1, dp);

            // Skip
            long long skip = helper(ind + 1, n, prices, k, 0, type, dp);

            res = max(sell, skip);
        }

        return dp[ind][k][canBuy][t] = res;
    }

    long long maximumProfit(vector<int>& prices, int k) 
    {
        int n = prices.size();

        vector<vector<vector<vector<long long>>>> dp(
            n,
            vector<vector<vector<long long>>>(
                k + 1,
                vector<vector<long long>>(
                    2,
                    vector<long long>(3, LLONG_MIN)
                )
            )
        );

        return helper(0, n, prices, k, 1, -1, dp);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter prices: ";
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    cout << "Enter max transactions: ";
    cin >> k;

    Solution sol;
    long long result = sol.maximumProfit(prices, k);

    cout << "Maximum Profit: " << result << "\n";

    return 0;
}
