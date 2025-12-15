// Problem Link: https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/description
// Date: 15/12/2025
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long sum = 1;   // total descent periods
        long long des = 1;   // current descent length

        for (int i = 1; i < n; i++) {
            if (prices[i] + 1 == prices[i - 1]) {
                des = des + 1;
            } else {
                des = 1;
            }
            sum += des;
        }
        return sum;
    }
};

int main() {
    // -------- Static Input --------
    vector<int> prices = {3, 2, 1, 4};

    // -------- Function Call --------
    Solution sol;
    long long result = sol.getDescentPeriods(prices);

    // -------- Output --------
    cout << "Number of smooth descent periods: " << result << endl;

    return 0;
}
