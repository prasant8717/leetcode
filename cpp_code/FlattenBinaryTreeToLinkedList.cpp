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
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        flatten(root->left);
        flatten(root->right);
        TreeNode *l = root->left;
        TreeNode *r = root->right;
        root->left = nullptr;
        root->right = l;
        TreeNode* tmp = root;
        while (tmp->right != nullptr)
            tmp = tmp->right;
        tmp->right = r;
    }
};
