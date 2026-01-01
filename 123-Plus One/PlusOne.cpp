// Problem Link: https://leetcode.com/problems/plus-one/description
// Date: 01/01/2026 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Traverse from last digit
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0;
        }

        // If all digits were 9
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    Solution obj;

    vector<int> digits = {9, 9, 9};

   
    vector<int> result = obj.plusOne(digits);

   
    cout << "Result: ";
    for (int d : result) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}