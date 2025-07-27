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
    pair<int, int> steal(TreeNode* root) {
            if (!root) {
                return make_pair(0, 0);
            }
            auto [la, lb] = steal(root->left);
            auto [ra, rb] = steal(root->right);
            return make_pair(root->val + lb + rb, max(la, lb) + max(ra, rb));
        };
    int rob(TreeNode* root) {
        auto [a, b] = steal(root);
        return max(a, b);
    }
};
