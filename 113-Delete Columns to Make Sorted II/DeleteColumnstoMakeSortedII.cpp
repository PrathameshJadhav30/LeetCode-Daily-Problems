// Problem Link: https://leetcode.com/problems/delete-columns-to-make-sorted-ii/description
// Date: 21/12/2025
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        // resolved[i] = true means strs[i] < strs[i+1] is already decided
        vector<bool> resolved(n - 1, false);
        int unresolved = n - 1;
        int deletions = 0;

        // Traverse column by column
        for (int col = 0; col < m && unresolved > 0; col++) {
            bool bad = false;

            // Check if this column violates lexicographical order
            for (int i = 0; i < n - 1; i++) {
                if (!resolved[i] && strs[i][col] > strs[i + 1][col]) {
                    bad = true;
                    break;
                }
            }

            // If bad column, delete it
            if (bad) {
                deletions++;
                continue;
            }

            // Otherwise, resolve comparisons that are strictly ordered
            for (int i = 0; i < n - 1; i++) {
                if (!resolved[i] && strs[i][col] < strs[i + 1][col]) {
                    resolved[i] = true;
                    unresolved--;
                }
            }
        }

        return deletions;
    }
};

int main() {
    vector<string> strs = {
        "ca",
        "bb",
        "ac"
    };

    Solution sol;
    int result = sol.minDeletionSize(strs);

    cout << "Minimum columns to delete: " << result << endl;

    return 0;
}