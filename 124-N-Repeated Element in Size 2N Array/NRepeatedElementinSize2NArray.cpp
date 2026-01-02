//Problem Link: https://leetcode.com/problems/n-repeated-element-in-size-2n-array/description
// Date: 02/01/2026
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for (int i = 0; i < A.size() - 2; ++i) {
            if (A[i] == A[i + 1] || A[i] == A[i + 2]) {
                return A[i];
            }
        }
        return A.back();
    }
};

int main() {
    Solution sol;

    
    vector<int> A = {1, 2, 3, 3};

    int result = sol.repeatedNTimes(A);

    cout << "Repeated element: " << result << endl;

    return 0;
}