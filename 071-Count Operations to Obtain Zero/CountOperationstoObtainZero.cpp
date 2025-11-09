//Problem Link: https://leetcode.com/problems/count-operations-to-obtain-zero/description
// Date: 09/11/2025
#include <iostream>
using namespace std;

class Solution {
public:
    int countOperations(int num1, int num2, int cnt = 0) {
        return (num1 == 0 || num2 == 0) ? cnt : countOperations(num2, num1 % num2, cnt + num1 / num2);
    }
};

int main() {
    Solution obj;

    int num1 = 10;
    int num2 = 4;

    int result = obj.countOperations(num1, num2);
    cout << "Input: num1 = " << num1 << ", num2 = " << num2 << endl;
    cout << "Number of operations required: " << result << endl;

    return 0;
}
