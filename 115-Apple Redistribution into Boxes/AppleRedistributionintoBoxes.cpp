// Problem Link: https://leetcode.com/problems/apple-redistribution-into-boxes/description
// Date: 24/12/2025
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& cap) {
        // Total apples
        int sum = accumulate(apple.begin(), apple.end(), 0);

        // Sort box capacities in descending order
        sort(cap.begin(), cap.end(), greater<int>());

        int res = 0;

        // Take boxes until all apples are stored
        while (sum > 0 && res < cap.size()) {
            sum -= cap[res];
            res++;
        }

        return res;
    }
};

int main() {
    Solution sol;

    vector<int> apple = {1, 3, 2};
    vector<int> cap = {4, 3, 1, 5, 2};

    int result = sol.minimumBoxes(apple, cap);

    cout << "Minimum number of boxes required: " << result << endl;

    return 0;
}

