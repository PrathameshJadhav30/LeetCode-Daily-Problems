//Problem Link: https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/description
// Date: 08/09/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to check if number contains digit '0'
    bool isNoZero(int num) {
        while (num > 0) {
            if (num % 10 == 0) { // if any digit is 0
                return false;
            }
            num /= 10;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        int a = 1, b = n - 1;

        // Keep adjusting until both are No-Zero integers
        while (!isNoZero(a) || !isNoZero(b)) {
            a++;
            b = n - a;
        }
        return {a, b};
    }
};

int main() {
    Solution s;
    int n;

    cout << "Enter an integer (2 <= n <= 10000): ";
    cin >> n;

    vector<int> result = s.getNoZeroIntegers(n);

    cout << "Two No-Zero integers are: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
