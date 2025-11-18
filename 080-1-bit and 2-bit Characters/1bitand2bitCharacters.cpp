//Problem Link: https://leetcode.com/problems/1-bit-and-2-bit-characters/description
// Date: 18/11/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;

        while (i < n - 1) {       // Stop before last bit
            if (bits[i] == 1)
                i += 2;          // Two-bit character
            else
                i += 1;          // One-bit character
        }

        return i == n - 1;       // Check if last char is 1-bit
    }
};

int main() {
    vector<int> bits = {1, 0, 0};

    Solution obj;
    bool result = obj.isOneBitCharacter(bits);

    cout << (result ? "true" : "false") << endl;

    return 0;
}
