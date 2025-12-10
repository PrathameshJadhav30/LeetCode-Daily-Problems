//Problem Link: https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations/description
// Date: 10/12/2025
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static const int MOD = 1000000007;

    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        int first = complexity[0];

        // Check if all other elements > first
        for (int i = 1; i < n; i++) {
            if (complexity[i] <= first) return 0;
        }

        long long fact = 1;
        for (int i = 2; i < n; i++) {
            fact = (fact * i) % MOD;
        }

        return (int)fact;
    }
};

int main() {
    Solution obj;

    vector<int> complexity = {2, 5, 7, 9};   

    cout << "Input Array: ";
    for(int x : complexity) cout << x << " ";
    cout << endl;

    int result = obj.countPermutations(complexity);
    cout << "Result = " << result << endl;

    return 0;
}
