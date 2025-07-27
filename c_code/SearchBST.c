/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    while(root != NULL) {
        if (root->val == val) {
            return root;
        }
        else if (root->val > val) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return NULL;
}
