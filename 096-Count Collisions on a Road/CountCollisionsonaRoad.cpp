// Problem Link: https://leetcode.com/problems/count-collisions-on-a-road/description
// Date: 04/12/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int countCollisions(string& D) {
        int n = D.size();
        if (n == 1) return 0;

        int l = D.find_first_not_of('L');
        if (l == -1) l = n - 1;

        int r = D.find_last_not_of('R');
        if (r == -1) r = 0;

        if (l >= r) return 0;

        return count_if(D.begin() + l, D.begin() + (r + 1),
                        [](char c) { return c != 'S'; });
    }
};

int main() {
    vector<string> tests = {
        "RLRSLL",
        "LLRR",
        "RSR",
        "SSSRLLRS",
        "LLLLL",
        "RRRRR",
        "RRSLSLRLLSR"
    };

    cout << "Collision results:\n";
    for (string D : tests) {
        cout << "Input: " << D 
             << " -> Collisions = " << Solution::countCollisions(D) << "\n";
    }

    // Custom user input
    cout << "\nEnter direction string (L R S): ";
    string input;
    cin >> input;

    cout << "Collisions = " << Solution::countCollisions(input) << endl;

    return 0;
}
