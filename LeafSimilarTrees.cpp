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
    vector<int> v1;
    vector<int> v2;
public:
    void update_vector(TreeNode* root, vector<int> &v) {
        if (root == nullptr) {
            return;
        } else {
            if (root->left == root->right) {
                v.push_back(root->val);
            }
        }
        update_vector(root->left, v);
        update_vector(root->right, v);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        update_vector(root1, v1);
        update_vector(root2, v2);
        bool sts = true;
        if (v1.size() == v2.size()) {
            for (int i = 0; i < v1.size(); ++i) {
                if (v1[i] != v2[i]) {
                    sts = false;
                    break;
                }
            }
        } else {
            sts = false;
        }
        return sts;
    }
};
