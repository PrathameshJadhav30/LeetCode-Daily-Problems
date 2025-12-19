// Problem Link: https://leetcode.com/problems/find-all-people-with-secret/description
// Date: 19/12/2025
#include <iostream>
#include <vector>   
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meet, int fp) {

        // Group meetings by time
        map<int, vector<pair<int,int>>> timeMeetings;
        for (auto &m : meet) {
            int x = m[0], y = m[1], t = m[2];
            timeMeetings[t].push_back({x, y});
        }

        // ks -> knows secret
        vector<bool> ks(n, false);
        ks[0] = true;
        ks[fp] = true;

        for (auto &entry : timeMeetings) {
            auto &meetings = entry.second;

            // Adjacency list for this time only
            unordered_map<int, vector<int>> meetList;
            for (auto &p : meetings) {
                meetList[p.first].push_back(p.second);
                meetList[p.second].push_back(p.first);
            }

            // Starting nodes (already know secret)
            queue<int> q;
            unordered_set<int> visited;

            for (auto &p : meetings) {
                if (ks[p.first]) {
                    q.push(p.first);
                    visited.insert(p.first);
                }
                if (ks[p.second]) {
                    q.push(p.second);
                    visited.insert(p.second);
                }
            }

            // BFS to spread secret at same time
            while (!q.empty()) {
                int person = q.front();
                q.pop();

                for (int nextPerson : meetList[person]) {
                    if (!visited.count(nextPerson)) {
                        ks[nextPerson] = true;
                        visited.insert(nextPerson);
                        q.push(nextPerson);
                    }
                }
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (ks[i]) res.push_back(i);
        }
        return res;
    }
};

int main() {
    Solution sol;

    int n = 6;
    int firstPerson = 1;

    vector<vector<int>> meetings = {
        {1, 2, 5},
        {2, 3, 8},
        {1, 5, 10}
    };

    vector<int> result = sol.findAllPeople(n, meetings, firstPerson);

    cout << "People who know the secret: ";
    for (int person : result) {
        cout << person << " ";
    }
    cout << endl;

    return 0;
}
