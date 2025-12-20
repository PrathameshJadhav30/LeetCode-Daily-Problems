// Problem Link: https://leetcode.com/problems/delete-columns-to-make-sorted/description
// date: 20/12/2025
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].size();
        int deleteCount = 0;

        // Check each column
        for (int col = 0; col < cols; col++) {
            for (int row = 1; row < rows; row++) {
                // If column is not sorted
                if (strs[row][col] < strs[row - 1][col]) {
                    deleteCount++;
                    break;
                }
            }
        }
        return deleteCount;
    }
};

int main() {
    Solution sol;

    vector<string> strs = {
        "cba",
        "daf",
        "ghi"
    };

    int result = sol.minDeletionSize(strs);

    cout << "Columns to delete: " << result << endl;

    return 0;
}
