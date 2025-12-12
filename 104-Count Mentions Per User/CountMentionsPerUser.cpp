// Problem Link: https://leetcode.com/problems/count-mentions-per-user/description
// Date: 12/12/2025
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        
        // Sort by (time, eventTypeCharacter)
        sort(events.begin(), events.end(), [](const auto& a, const auto& b) {
            int t1 = stoi(a[1]);
            int t2 = stoi(b[1]);
            if (t1 != t2) return t1 < t2;
            return a[0][2] < b[0][2];
        });

        vector<int> ans(numberOfUsers, 0);
        vector<int> online_t(numberOfUsers, 0);

        for (auto &e : events) {
            int cur_t = stoi(e[1]);
            string mention = e[2];

            // O event : user becomes online
            if (e[0][0] == 'O') {
                int user = stoi(mention);
                online_t[user] = cur_t + 60;
            }
            // @ALL
            else if (mention[0] == 'A') {
                for (int i = 0; i < numberOfUsers; i++) ans[i]++;
            }
            // @HERE
            else if (mention[0] == 'H') {
                for (int i = 0; i < numberOfUsers; i++) {
                    if (online_t[i] <= cur_t) ans[i]++;
                }
            }
            // "@U X Y ..."
            else {
                // Split manually
                string temp = "";
                for (char c : mention + " ") {
                    if (c == ' ') {
                        if (temp.rfind("@U", 0) == 0) {
                            string num = temp.substr(2);
                            ans[stoi(num)]++;
                        }
                        temp.clear();
                    } else {
                        temp += c;
                    }
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    int numberOfUsers = 5;

    vector<vector<string>> events = {
        {"O", "1", "0"},
        {"M", "2", "@ALL"},
        {"M", "3", "@U 0 1"},
        {"M", "4", "@HERE"}
    };

    vector<int> result = sol.countMentions(numberOfUsers, events);

    cout << "Output: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
