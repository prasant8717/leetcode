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
    void nodes(TreeNode *r, vector<int>& v) {
        if (r == nullptr)
            return;
        nodes(r->left, v);
        v.push_back(r->val);
        nodes(r->right, v);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        nodes(root, v);
        int l = 0;
        int r = v.size() - 1;
        while (l < r) {
            int t = v[l] + v[r];
            if (t == k)
                return true;
            else if (t < k)
                ++ l;
            else
                -- r;
        }
        return false;
    }
};
