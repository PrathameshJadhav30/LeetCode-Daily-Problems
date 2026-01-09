// Problem Link: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description
// Date: 09/01/2026
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root) return nullptr;

        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        parent[root] = nullptr;

        vector<TreeNode*> lastLevel;

        // BFS traversal to get deepest level
        while (!q.empty()) {
            int size = q.size();
            lastLevel.clear();

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                lastLevel.push_back(node);

                if (node->left) {
                    parent[node->left] = node;
                    q.push(node->left);
                }
                if (node->right) {
                    parent[node->right] = node;
                    q.push(node->right);
                }
            }
        }

        unordered_set<TreeNode*> deepest(lastLevel.begin(), lastLevel.end());

        // Move all deepest nodes upward until one common ancestor remains
        while (deepest.size() > 1) {
            unordered_set<TreeNode*> next;
            for (auto node : deepest) {
                next.insert(parent[node]);
            }
            deepest = next;
        }

        return *deepest.begin();
    }
};

int main() {
    /*
        Sample Tree:
                3
               / \
              5   1
             / \ / \
            6  2 0  8
              / \
             7   4

        Output: 2 (subtree containing deepest nodes 7 and 4)
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;
    TreeNode* result = sol.subtreeWithAllDeepest(root);

    if (result) {
        cout << "Subtree with all deepest nodes root value: "
             << result->val << endl;
    } else {
        cout << "Tree is empty" << endl;
    }

    return 0;
}