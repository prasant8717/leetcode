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
    void reverse(TreeNode *l, TreeNode *r, bool odd) {
        if (l == nullptr)
            return;
        if (odd == true) {
            int t = l->val;
            l->val = r->val;
            r->val = t;
        }
        reverse(l->left, r->right, !odd);
        reverse(l->right, r->left, !odd);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        reverse(root->left, root->right, true);
        return root;
    }
};
