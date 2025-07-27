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
    int pathsum(TreeNode* root, int& max) {
        if (root == nullptr)
            return 0;
        int l = pathsum(root->left, max);
        if (l < 0) {
            l = 0;
        }
        int r = pathsum(root->right, max);
        if (r < 0) {
            r = 0;
        }
        int tmp = root->val + l + r;
        if (tmp > max) {
            max = tmp;
        }
        return root->val + ((l > r) ? l : r);
    }
    int maxPathSum(TreeNode* root) {
        int max = INT_MIN;
        pathsum(root, max);
        return max;
    }
};
