/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<TreeNode*, int> lca(TreeNode* root) {
        if (!root)
            return {nullptr, 0};
        pair<TreeNode*, int> p1 = lca(root->left);
        pair<TreeNode*, int> p2 = lca(root->right);
        if (p1.second > p2.second)
            return {p1.first, p1.second + 1};
        if (p1.second < p2.second)
            return {p2.first, p2.second + 1};
        return {root, p1.second + 1};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return lca(root).first;
    }
};
