//Problem Link: https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/description
// Date: 30/10/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int sum = target[0]; // start with first element
        for (int i = 1; i < target.size(); i++) {
            if (target[i] > target[i - 1]) {
                sum += target[i] - target[i - 1]; // add only when value increases
            }
        }
        return sum; // total operations needed
    }
};

int main() {
    Solution obj;

    vector<int> target = {1, 2, 3, 2, 1};

    // Function call
    int result = obj.minNumberOperations(target);

    // Output result
    cout << "Minimum number of operations: " << result << endl;

    return 0;
}
