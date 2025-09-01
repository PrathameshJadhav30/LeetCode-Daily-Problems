//Problem Link: https://leetcode.com/problems/maximum-average-pass-ratio/description
//Date: 01/09/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };

        priority_queue<pair<double, pair<int,int>>> pq;
        for (auto& c : classes) {
            pq.push({gain(c[0], c[1]), {c[0], c[1]}});
        }

        while (extraStudents--) {
            auto [g, cls] = pq.top(); pq.pop();
            int pass = cls.first, total = cls.second;
            pass++; total++;
            pq.push({gain(pass, total), {pass, total}});
        }

        double sum = 0.0;
        while (!pq.empty()) {
            auto [g, cls] = pq.top(); pq.pop();
            sum += (double)cls.first / cls.second;
        }

        return sum / classes.size();
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> classes1 = {{1,2},{3,5},{2,2}};
    int extraStudents1 = 2;
    cout << fixed << setprecision(5);
    cout << "Example 1 Output: " << sol.maxAverageRatio(classes1, extraStudents1) << endl;

    // Example 2
    vector<vector<int>> classes2 = {{2,4},{3,9},{4,5},{2,10}};
    int extraStudents2 = 4;
    cout << "Example 2 Output: " << sol.maxAverageRatio(classes2, extraStudents2) << endl;

    // Custom input
    int n, extra;
    cout << "\nEnter number of classes: ";
    cin >> n;
    cout << "Enter extra students: ";
    cin >> extra;

    vector<vector<int>> classes(n, vector<int>(2));
    cout << "Enter each class as <pass total>:\n";
    for (int i = 0; i < n; i++) {
        cin >> classes[i][0] >> classes[i][1];
    }

    double ans = sol.maxAverageRatio(classes, extra);
    cout << "Maximum Average Pass Ratio: " << ans << endl;

    return 0;
}
