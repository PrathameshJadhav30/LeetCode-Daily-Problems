// Problem Link: https://leetcode.com/problems/minimum-penalty-for-a-shop/description
// Date: 26/12/2025
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int bestTime = 0;
        int minPenalty = 0;
        int prefix = 0;

        for (int i = 0; i < customers.length(); i++) {
            // 'Y' increases penalty if closed, so reduce
            // 'N' increases penalty if open
            prefix += (customers[i] == 'Y') ? -1 : 1;

            if (prefix < minPenalty) {
                minPenalty = prefix;
                bestTime = i + 1;
            }
        }

        return bestTime;
    }
};

int main() {
    Solution obj;

    // Test cases
    string customers1 = "YYNY";
    string customers2 = "NNNN";
    string customers3 = "YYYY";
    string customers4 = "YNYNY";

    cout << "Best closing time for \"" << customers1 << "\" : "
         << obj.bestClosingTime(customers1) << endl;

    cout << "Best closing time for \"" << customers2 << "\" : "
         << obj.bestClosingTime(customers2) << endl;

    cout << "Best closing time for \"" << customers3 << "\" : "
         << obj.bestClosingTime(customers3) << endl;

    cout << "Best closing time for \"" << customers4 << "\" : "
         << obj.bestClosingTime(customers4) << endl;

    return 0;
}
