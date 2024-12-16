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
    int compute(TreeNode *r, int& s) {
        if (r == nullptr)
            return 0;
        int ls = compute(r->left, s);
        int rs = compute(r->right, s);
        int t = ls - rs;
        if (t < 0)
            s = s - t;
        else
            s = s + t;
        return r->val + ls + rs;
    }
    int findTilt(TreeNode* root) {
        int res  = 0;
        compute(root, res);
        return res;
    }
};
