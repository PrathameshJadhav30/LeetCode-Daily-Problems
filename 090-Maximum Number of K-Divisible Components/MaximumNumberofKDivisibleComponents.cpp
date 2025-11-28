// Problem Link: https://leetcode.com/problems/maximum-number-of-k-divisible-components/description
// Date: 28/11/2025
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans = 0, K;
    vector<vector<int>> adj;

    long dfs(int node, int parent, vector<int>& values) {
        long sum = values[node];
        for (int nxt : adj[node]) {
            if (nxt != parent) sum += dfs(nxt, node, values);
        }
        if (sum % K == 0) ans++;
        return sum % K;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        adj.assign(n, {});
        K = k;

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1, values);
        return ans;
    }
};

int main() {
    int n = 6;
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {1, 3}, {3, 4}, {3, 5}
    };

    vector<int> values = {2, 3, 6, 4, 1, 5};
    int k = 3;

    Solution sol;
    int result = sol.maxKDivisibleComponents(n, edges, values, k);

    cout << "Maximum K-Divisible Components: " << result << endl;

    return 0;
}
