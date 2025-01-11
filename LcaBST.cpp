/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int t = p->val;
        if (t < q->val)
            t = q->val;
        if (root->val > t)
            return lowestCommonAncestor(root->left, p, q);
        t = p->val;
        if (t > q->val)
            t = q->val;        
        if (root->val < t)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
