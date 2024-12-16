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
    int findSecondMinimumValue(TreeNode* root) {
        vector<int> v;
        traverse(root, v);
        ranges::sort(v);
        int min = v[0];
        for (int i = 1; i < v.size(); ++ i) {
            if (v[i] != v[0])
                return v[i];
        }
        return -1;
    }
};
