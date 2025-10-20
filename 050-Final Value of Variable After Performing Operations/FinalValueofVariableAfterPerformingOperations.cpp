//Problem Link: https://leetcode.com/problems/final-value-of-variable-after-performing-operations/description
//Date: 20/10/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (auto& op : operations)
            x += (op[1] == '+') ? 1 : -1;
        return x;
    }
};

int main() {
    Solution obj;

    vector<string> operations = {"--X", "X++", "X++"};
    
    int result = obj.finalValueAfterOperations(operations);
    cout << "Final value of X: " << result << endl;

    return 0;
}
