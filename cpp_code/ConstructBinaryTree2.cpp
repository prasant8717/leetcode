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
    TreeNode* add_node(vector<int>& post, unordered_map<int, int>& map, int p, int l, int r) {
        if (r <= 0) {
            return nullptr;
        }
        int val = post[l + r - 1];
        int mid = map[val];
        TreeNode *root = new TreeNode(val);
        root->left = add_node(post, map, p, l, mid - p);
        root->right = add_node(post, map, mid + 1, l + mid - p, r - mid + p - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> map;
        for (int i = 0; i < inorder.size(); i ++) {
            map[inorder[i]] = i;
        }
        return add_node(postorder, map, 0, 0, inorder.size());        
    }
};
