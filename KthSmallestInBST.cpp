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
    void inorder(TreeNode* root, int k, int& lvl, int& out) {
        if (root == nullptr)
            return;
        inorder(root->left, k, lvl, out);
        lvl ++;
        if (lvl == k) {
            out = root->val;
            return;
        }
        inorder(root->right, k, lvl, out);
    }

    int kthSmallest(TreeNode* root, int k) {
        int out = -1;
        int lvl = 0;
        inorder(root, k, lvl, out);
        return out;        
    }
};
