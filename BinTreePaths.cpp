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
    void paths(TreeNode *r, vector<string>& p, vector<string>& v) {
        if (r == nullptr)
            return;
        if ((r->left == nullptr) && (r->right == nullptr)) {
            string s;
            for (int i = 0; i < p.size(); ++ i)
                s += p[i];
            v.push_back(s + to_string(r->val));
            return;
        }
        p.push_back(to_string(r->val) + "->");
        paths(r->left, p, v);
        paths(r->right, p, v);
        p.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> out;
        vector<string> p;
        paths(root, p, out);
        return out;
    }
};
