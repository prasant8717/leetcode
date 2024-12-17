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
    void traverse(TreeNode *r, vector<int>& v) {
        if (r == nullptr)
            return;
        traverse(r->left, v);
        v.push_back(r->val);
        traverse(r->right, v);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> v;
        traverse(root, v);
        int min = 1e5;
        for (int i = 0; i < v.size() - 1; ++ i) {
            int t = v[i + 1] - v[i];
            if (t < min)
                min = t;
        }
        return min;
    }
};
