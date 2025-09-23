//Problem Link: https://leetcode.com/problems/compare-version-numbers/description
// Date: 23/09/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;   // pointers for both strings
        int n1 = version1.size();
        int n2 = version2.size();

        while (i < n1 || j < n2) {   // continue until both are processed
            int num1 = 0, num2 = 0;

            // Extract number from version1
            while (i < n1 && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0'); // convert to int
                i++;
            }

            // Extract number from version2
            while (j < n2 && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }

            // Compare numbers
            if (num1 < num2) return -1;
            if (num1 > num2) return 1;

            // Skip the '.' character
            i++;
            j++;
        }

        // If all revisions equal
        return 0;
    }
};

int main() {
    Solution sol;

    // Test cases
    cout << sol.compareVersion("1.2", "1.10") << endl;     // Output: -1
    cout << sol.compareVersion("1.01", "1.001") << endl;   // Output: 0
    cout << sol.compareVersion("1.0", "1.0.0.0") << endl;  // Output: 0
    cout << sol.compareVersion("2.1", "2.0.9") << endl;    // Output: 1

    return 0;
}
