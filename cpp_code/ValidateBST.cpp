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
    void inorder(TreeNode *root, vector<int>& v) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> vec;
        inorder(root, vec);
        bool sts = true;
        for (int i = 0; i < vec.size() - 1; ++ i) {
            if (vec[i] >= vec[i + 1]) {
                sts = false;
                break;
            }
        }
        return sts;
    }
};
