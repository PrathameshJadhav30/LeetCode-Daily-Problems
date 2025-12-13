//Problem Link: https://leetcode.com/problems/coupon-code-validator/description
// Date: 13/12/2025
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cctype>

using namespace std;

class Solution {
public:
    vector<string> validateCoupons(
        vector<string>& code,
        vector<string>& businessLine,
        vector<bool>& isActive
    ) {
        int n = code.size();

        // Business line sorting order
        unordered_map<string, int> businessLineSortOrder = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        // (businessOrder, code) -> code
        vector<pair<pair<int, string>, string>> sortableCoupons;

        for (int i = 0; i < n; i++) {

            // Check active
            if (!isActive[i])
                continue;

            // Check valid business line
            if (businessLineSortOrder.find(businessLine[i]) ==
                businessLineSortOrder.end())
                continue;

            // Check valid coupon code
            if (code[i].empty())
                continue;

            bool isCodeValid = true;
            for (char c : code[i]) {
                if (!(isalnum(c) || c == '_')) {
                    isCodeValid = false;
                    break;
                }
            }

            if (!isCodeValid)
                continue;

            int order = businessLineSortOrder[businessLine[i]];
            sortableCoupons.push_back({{order, code[i]}, code[i]});
        }

        // Sort by business line order, then by code
        sort(sortableCoupons.begin(), sortableCoupons.end());

        vector<string> result;
        for (auto &entry : sortableCoupons) {
            result.push_back(entry.second);
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<string> code = {
        "SAVE_10",
        "FOOD50",
        "ELEC@20",
        "",
        "MED123",
        "REST_5"
    };

    vector<string> businessLine = {
        "electronics",
        "restaurant",
        "electronics",
        "grocery",
        "pharmacy",
        "restaurant"
    };

    vector<bool> isActive = {
        true,
        true,
        true,
        true,
        false,
        true
    };

    vector<string> result = sol.validateCoupons(code, businessLine, isActive);

    
    cout << "Valid Coupons (Sorted):\n";
    for (const string &s : result) {
        cout << s << endl;
    }

    return 0;
}
