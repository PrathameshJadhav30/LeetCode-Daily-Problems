// Problem Link: https://leetcode.com/problems/power-grid-maintenance/description
// Date: 06/11/2025
#include <bits/stdc++.h>
using namespace std;

const int N = 100001;
int root[N];
vector<int> adj[N];

class Solution {
public:
    bitset<N> viz;
    vector<set<int>> comp;

    // Build adjacency list
    void build_adj(int c, vector<vector<int>>& connections) {
        for (int i = 1; i <= c; i++) adj[i].clear();
        for (auto& e : connections) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    // Depth First Search to find components
    void dfs(int i0, int i) {
        root[i] = i0;
        comp[i0].insert(i);
        viz[i] = 1;
        for (int j : adj[i]) {
            if (viz[j]) continue;
            dfs(i0, j);
        }
    }

    // Process all queries
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        viz.reset();
        comp.clear();
        comp.resize(c + 1);

        build_adj(c, connections);

        // Build connected components
        for (int i = 1; i <= c; i++) {
            if (!viz[i]) dfs(i, i);
        }

        vector<int> ans;
        for (auto& q : queries) {
            int t = q[0], x = q[1];
            int rx = root[x];
            auto& C = comp[rx];

            if (t == 2) {
                // Remove node from component
                C.erase(x);
            } else {
                // Query operation
                if (C.empty()) ans.push_back(-1);
                else if (C.count(x)) ans.push_back(x);
                else ans.push_back(*C.begin());
            }
        }
        return ans;
    }
};

// -----------------------------
// MAIN FUNCTION FOR TESTING
// -----------------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    // Example Input:
    // c = 5 (number of nodes)
    // connections = [[1,2],[2,3],[4,5]]
    // queries = [[1,1],[2,2],[1,3],[1,5]]

    int c = 5;
    vector<vector<int>> connections = {
        {1, 2},
        {2, 3},
        {4, 5}
    };

    vector<vector<int>> queries = {
        {1, 1},
        {2, 2},
        {1, 3},
        {1, 5}
    };

    // Process queries
    vector<int> result = sol.processQueries(c, connections, queries);

    cout << "Query Results:\n";
    for (int x : result)
        cout << x << " ";
    cout << "\n";

    return 0;
}
