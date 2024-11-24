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
    void path(TreeNode *r, int s, vector<int>& p, vector<vector<int>>& o) {
        if (r == nullptr)
            return;
        if ((r->val == s) && (r->left == nullptr) &&
            (r->right == nullptr)) {
            p.push_back(r->val);
            o.push_back(p);
            p.pop_back();
            return;
        }
        p.push_back(r->val);
        path(r->left, s - r->val, p, o);
        path(r->right, s - r->val, p, o);
        p.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> p;
        vector<vector<int>> out;
        path(root, targetSum, p, out);
        return out;
    }
};
