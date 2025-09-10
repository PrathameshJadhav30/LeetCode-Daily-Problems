//Problem Link: https://leetcode.com/problems/minimum-number-of-people-to-teach/description
//Date: 10/09/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();

        // Convert to sets for quick lookup
        vector<unordered_set<int>> userLang(m + 1);
        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                userLang[i + 1].insert(lang);
            }
        }

        // Step 1: Find users involved in problematic friendships
        unordered_set<int> problematicUsers;
        for (auto& f : friendships) {
            int u = f[0], v = f[1];
            bool canCommunicate = false;
            for (int lang : userLang[u]) {
                if (userLang[v].count(lang)) {
                    canCommunicate = true;
                    break;
                }
            }
            if (!canCommunicate) {
                problematicUsers.insert(u);
                problematicUsers.insert(v);
            }
        }

        // Step 2: If no problematic users, no need to teach
        if (problematicUsers.empty()) return 0;

        // Step 3: Count how many problematic users already know each language
        vector<int> count(n + 1, 0);
        for (int user : problematicUsers) {
            for (int lang : userLang[user]) {
                count[lang]++;
            }
        }

        // Step 4: Minimize number of teachings
        int total = problematicUsers.size();
        int maxAlreadyKnow = 0;
        for (int lang = 1; lang <= n; lang++) {
            maxAlreadyKnow = max(maxAlreadyKnow, count[lang]);
        }

        return total - maxAlreadyKnow;
    }
};

int main() {
    Solution sol;

    // Example 1
    int n1 = 2;
    vector<vector<int>> languages1 = {{1}, {2}, {1, 2}};
    vector<vector<int>> friendships1 = {{1, 2}, {1, 3}, {2, 3}};
    cout << "Example 1 Output: " 
         << sol.minimumTeachings(n1, languages1, friendships1) << endl;

    // Example 2
    int n2 = 3;
    vector<vector<int>> languages2 = {{2}, {1, 3}, {1, 2}, {3}};
    vector<vector<int>> friendships2 = {{1, 4}, {1, 2}, {3, 4}, {2, 3}};
    cout << "Example 2 Output: " 
         << sol.minimumTeachings(n2, languages2, friendships2) << endl;

    return 0;
}
