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
    TreeNode *traverse(TreeNode *root, TreeNode *end) {
        if (root == nullptr)
            return end;
        TreeNode *res = traverse(root->left, root);
        root->left = nullptr;
        root->right = traverse(root->right, end);
        return res;
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *out = traverse(root, nullptr);
        return out;
    }
};
