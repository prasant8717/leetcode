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
    bool subtree(TreeNode *r, TreeNode *sr) {
        if ((r == nullptr) || (sr == nullptr))
            return r == sr;
        bool s = (r->val == sr->val);
        return s && subtree(r->left, sr->left) && subtree(r->right, sr->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr)
            return false;
        bool rs = subtree(root, subRoot);
        bool lrs = isSubtree(root->left, subRoot);
        bool rrs = isSubtree(root->right, subRoot);
        return (rs || lrs || rrs);
    }
};
