//Problem Link: https://leetcode.com/problems/maximum-profit-from-trading-stocks-with-discounts/description
// Date: 16/12/2025
#include <iostream>
#include <vector>
#include <bitset>
#include <climits>
using namespace std;

const int N = 161;
const int N4 = N * 4;

int profitArr[N][2];
vector<int> children[N];
int dp[N][2][2][N];  // node, bossBuy, buy, budget
bitset<N4> vis;      // visited states

class Solution {
public:
    int n;

    void build_tree(const vector<vector<int>>& hierarchy) {
        for (int i = 0; i < n; i++)
            children[i].clear();

        for (auto &e : hierarchy) {
            int parent = e[0] - 1;
            int child  = e[1] - 1;
            children[parent].push_back(child);
        }
    }

    void dfs(int node, bool bossBuy, bool buy, int budget,
             const vector<int>& present) {

        int state = (node << 2) | (bossBuy << 1) | buy;
        if (vis[state]) return;
        vis[state] = 1;

        int* cache = dp[node][bossBuy][buy];
        fill(cache, cache + budget + 1, INT_MIN);

        int cost = buy ? (bossBuy ? present[node] / 2 : present[node]) : 0;
        if (cost <= budget)
            cache[cost] = buy ? profitArr[node][bossBuy] : 0;

        vector<int> cur(cache, cache + budget + 1);
        vector<int> merged(budget + 1, INT_MIN);

        for (int child : children[node]) {
            dfs(child, buy, 1, budget, present);
            dfs(child, 0, 0, budget, present);

            int* take = dp[child][buy][1];
            int* skip = dp[child][0][0];

            fill(merged.begin(), merged.end(), INT_MIN);

            for (int b = 0; b <= budget; b++) {
                if (cur[b] == INT_MIN) continue;

                for (int x = 0; b + x <= budget; x++) {
                    int best = max(take[x], skip[x]);
                    if (best != INT_MIN) {
                        merged[b + x] = max(merged[b + x],
                                            cur[b] + best);
                    }
                }
            }
            cur = merged;
        }

        copy(cur.begin(), cur.end(), cache);
    }

    int maxProfit(int n, vector<int>& present, vector<int>& future,
                  vector<vector<int>>& hierarchy, int budget) {

        this->n = n;
        vis.reset();

        for (int i = 0; i < n; i++) {
            profitArr[i][0] = future[i] - present[i];
            profitArr[i][1] = future[i] - present[i] / 2;
        }

        build_tree(hierarchy);

        dfs(0, 0, 0, budget, present);
        dfs(0, 0, 1, budget, present);

        int ans = 0;
        for (int b = 0; b <= budget; b++) {
            ans = max(ans, dp[0][0][0][b]);
            ans = max(ans, dp[0][0][1][b]);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    int n = 3;
    vector<int> present = {10, 5, 6};
    vector<int> future  = {20, 8, 12};

    vector<vector<int>> hierarchy = {
        {1, 2},
        {1, 3}
    };

    int budget = 15;

    cout << "Maximum Profit = "
         << sol.maxProfit(n, present, future, hierarchy, budget)
         << endl;

    return 0;
}
