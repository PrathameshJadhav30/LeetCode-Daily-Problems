//Problem Link:https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/description
//Date: 19/10/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> vis;
        string smallest = s;
        queue<string> q;
        q.push(s);
        vis.insert(s);

        while (!q.empty()) {
            string cur = q.front(); 
            q.pop();
            if (cur < smallest) smallest = cur;

            // Operation 1: Add 'a' to every digit at odd indices
            string added = cur;
            for (int i = 1; i < added.size(); i += 2)
                added[i] = ((added[i] - '0' + a) % 10) + '0';
            if (!vis.count(added)) {
                vis.insert(added);
                q.push(added);
            }

            // Operation 2: Rotate string by 'b' positions
            string rotated = cur.substr(cur.size() - b) + cur.substr(0, cur.size() - b);
            if (!vis.count(rotated)) {
                vis.insert(rotated);
                q.push(rotated);
            }
        }
        return smallest;
    }
};

int main() {
    Solution sol;

    string s = "5525";
    int a = 9;
    int b = 2;

    string result = sol.findLexSmallestString(s, a, b);

    cout << "Lexicographically Smallest String: " << result << endl;

    return 0;
}
