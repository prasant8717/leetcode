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
    int cnt;
    int mx;
    void find_node(TreeNode* root, int x) {
        if (root == nullptr) {
            return;
        }
        if (root->val >= x) {
            cnt ++;
        }
        find_node(root->left, max(x, root->val));
        find_node(root->right, max(x, root->val));
    }
    int goodNodes(TreeNode* root) {
        mx = INT_MIN;
        cnt = 0;
        find_node(root, mx);
        return cnt;
    }
};
