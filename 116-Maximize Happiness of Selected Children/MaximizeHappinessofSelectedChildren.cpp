// Problem Link: https://leetcode.com/problems/maximize-happiness-of-selected-children/description
// Date: 25/12/2025
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // Sort happiness in descending order
        sort(happiness.begin(), happiness.end(), greater<int>());

        long long maxSum = 0;

        // Pick top k happiest people
        for (int i = 0; i < k; i++) {
            long long current = happiness[i] - i;

            // Only add if happiness is positive
            if (current > 0)
                maxSum += current;
            else
                break; // further values will only be smaller
        }

        return maxSum;
    }
};

int main() {
    Solution sol;
    vector<int> happiness = {1, 2, 3};
    int k = 2;

    cout << sol.maximumHappinessSum(happiness, k) << endl; 
    return 0;
}