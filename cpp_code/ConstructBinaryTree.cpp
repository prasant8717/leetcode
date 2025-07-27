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
    TreeNode* add_node(vector<int>& pre, unordered_map<int, int>& map, int p, int l, int r) {
        int mid = map[pre[p]];
        TreeNode* root = new TreeNode(pre[p]);
        if (mid > l) {
            root->left = add_node(pre, map, p + 1, l, mid - 1);
        }
        if (mid < r) {
            root->right = add_node(pre, map, p + mid - l + 1, mid + 1, r);
        }
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> map;
        for (int i = 0; i < inorder.size(); i ++) {
            map[inorder[i]] = i;
        }
        return add_node(preorder, map, 0, 0, inorder.size() - 1);
    }
};
