//Problem Link: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description
// Date: 06/01/2026
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

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
    vector<long long> sum = {LLONG_MIN}; // index 0 dummy

    void dfs(TreeNode* node, int level = 1) {
        if (node == nullptr) return;

        if (sum.size() == level)
            sum.push_back(node->val);
        else
            sum[level] += node->val;

        dfs(node->left, level + 1);
        dfs(node->right, level + 1);
    }

    int maxLevelSum(TreeNode* root) {
        dfs(root);
        return max_element(sum.begin(), sum.end()) - sum.begin();
    }
};

int main() {
    /*
        Sample Tree:
                1
               / \
              7   0
             / \
            7  -8

        Level sums:
        Level 1 -> 1
        Level 2 -> 7 + 0 = 7
        Level 3 -> 7 + (-8) = -1

        Answer = Level 2
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);

    Solution sol;
    int result = sol.maxLevelSum(root);

    cout << "Maximum Level Sum is at Level: " << result << endl;

    return 0;
}
