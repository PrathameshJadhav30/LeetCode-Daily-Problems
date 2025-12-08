// Problem Link: https://leetcode.com/problems/count-square-sum-triples/description
// Date: 08/12/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTriples(int n) {
        int res = 0;
        for (int u = 2; u <= sqrt(n); u++) {
            for (int v = 1; v < u; v++) {
                // Skip if (u - v) is even OR gcd(u,v) != 1
                if (~(u - v) & 1 || __gcd(u, v) != 1) continue;
                
                int c = u * u + v * v;
                if (c > n) continue;

                res += (n / c) << 1;   // Multiply by 2
            }
        }
        return res;
    }
};

int main() {
    Solution obj;

    int n = 10;      

    cout << "Input: n = " << n << endl;
    cout << "Count of Pythagorean Triples: " << obj.countTriples(n) << endl;

    return 0;
}
