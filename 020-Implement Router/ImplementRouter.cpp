//Problem statement: https://leetcode.com/problems/implement-router/description
//Date: 20/09/2025
#include <bits/stdc++.h>
using namespace std;

class Router {
    int memoryLimit;
    queue<tuple<int,int,int>> q; // FIFO queue of packets
    unordered_set<string> packetSet; // for duplicate detection
    unordered_map<int, vector<int>> destToTimestamps; // destination -> timestamps

    // Helper to create unique key for (src, dst, ts)
    string makeKey(int s, int d, int t) {
        return to_string(s) + "|" + to_string(d) + "|" + to_string(t);
    }

public:
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source, destination, timestamp);
        if (packetSet.count(key)) {
            return false; // duplicate
        }

        // Evict if memory full
        if ((int)q.size() >= memoryLimit) {
            auto [s, d, t] = q.front();
            q.pop();
            string oldKey = makeKey(s, d, t);
            packetSet.erase(oldKey);

            // Remove timestamp t from destToTimestamps[d]
            auto &vec = destToTimestamps[d];
            auto it = lower_bound(vec.begin(), vec.end(), t);
            if (it != vec.end() && *it == t) {
                vec.erase(it);
            }
        }

        // Insert new packet
        q.push({source, destination, timestamp});
        packetSet.insert(key);
        destToTimestamps[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if (q.empty()) return {};
        auto [s, d, t] = q.front();
        q.pop();

        string key = makeKey(s, d, t);
        packetSet.erase(key);

        // Remove timestamp t from destToTimestamps[d]
        auto &vec = destToTimestamps[d];
        auto it = lower_bound(vec.begin(), vec.end(), t);
        if (it != vec.end() && *it == t) {
            vec.erase(it);
        }

        return {s, d, t};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if (!destToTimestamps.count(destination)) return 0;
        auto &vec = destToTimestamps[destination];
        int left = lower_bound(vec.begin(), vec.end(), startTime) - vec.begin();
        int right = upper_bound(vec.begin(), vec.end(), endTime) - vec.begin();
        return right - left;
    }
};

int main() {
    cout << "Example 1:\n";
    Router router1(3); // Initialize Router with memoryLimit of 3
    cout << boolalpha;
    cout << router1.addPacket(1, 4, 90) << "\n";   // true
    cout << router1.addPacket(2, 5, 90) << "\n";   // true
    cout << router1.addPacket(1, 4, 90) << "\n";   // false (duplicate)
    cout << router1.addPacket(3, 5, 95) << "\n";   // true
    cout << router1.addPacket(4, 5, 105) << "\n";  // true (evicts [1,4,90])

    auto p1 = router1.forwardPacket();             // [2, 5, 90]
    if (!p1.empty()) cout << "[" << p1[0] << "," << p1[1] << "," << p1[2] << "]\n";
    else cout << "[]\n";

    cout << router1.addPacket(5, 2, 110) << "\n";  // true
    cout << router1.getCount(5, 100, 110) << "\n"; // 1 (only [4,5,105])

    cout << "\nExample 2:\n";
    Router router2(2); // Initialize Router with memoryLimit of 2
    cout << router2.addPacket(7, 4, 90) << "\n";   // true

    auto p2 = router2.forwardPacket();             // [7, 4, 90]
    if (!p2.empty()) cout << "[" << p2[0] << "," << p2[1] << "," << p2[2] << "]\n";
    else cout << "[]\n";

    auto p3 = router2.forwardPacket();             // []
    if (!p3.empty()) cout << "[" << p3[0] << "," << p3[1] << "," << p3[2] << "]\n";
    else cout << "[]\n";

    return 0;
}
