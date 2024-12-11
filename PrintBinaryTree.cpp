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
    int height(TreeNode *r) {
        if (r == nullptr)
            return -1;
        int lh = height(r->left);
        int rh = height(r->right);
        int l = lh;
        if (l < rh)
            l = rh;
        return l + 1;
    }
    void construct(TreeNode *r, vector<vector<string>>& v, int h, int b, int c) {
        if (r == nullptr)
            return;
        v[b][c] = to_string(r->val);
        construct(r->left, v, h, b + 1, c - pow(2, h - b - 1));
        construct(r->right, v, h, b + 1, c + pow(2, h - b - 1));
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root);
        int m = h + 1;
        int n = (1 << (h + 1)) - 1;
        vector<vector<string>> out(m, vector<string>(n, ""));
        construct(root, out, h, 0, (n - 1) >> 1);
        return out;
    }
};
