// Problem Link: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description
// Date: 07/01/2026
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    long long val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(long long x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    long long MOD = 1e9 + 7;
    long long ans = 0;

    // DFS to calculate subtree sums
    long long dfs(TreeNode* node) {
        if (!node) return 0;

        node->val += dfs(node->left) + dfs(node->right);
        return node->val;
    }

    int maxProduct(TreeNode* root) {
        long long total = dfs(root);

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!node) continue;

            long long cur = (total - node->val) * node->val;
            ans = max(ans, cur);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        return ans % MOD;
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    /*
        Example Tree:
                1
               / \
              2   3
             / \   \
            4   5   6

        Expected Output: 110
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(6);

    Solution sol;
    cout << "Maximum Product: " << sol.maxProduct(root) << endl;

    return 0;
}
