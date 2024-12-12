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
    TreeNode *tn = nullptr;
    void traverse(TreeNode *r, vector<int>& v,
                  int& tc, int& mx) {
        if (r == nullptr)
            return;
        traverse(r->left, v, tc, mx);
        if ((tn != nullptr) && (tn->val == r->val))
            tc ++;
        else
            tc = 1;
        if (tc > mx) {
            mx = tc;
            v = {r->val};
        } else if (tc == mx) {
            v.push_back(r->val);
        }
        tn = r;
        traverse(r->right, v, tc, mx);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> v;
        int tc = 0;
        int mx = 0;
        traverse(root, v, tc, mx);
        return v;
    }
};
