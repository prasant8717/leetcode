/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (root->val == key) {
        if (root->left == NULL) {
            struct TreeNode *r = root->right;
            free(root);
            return r;
        }
        if (root->right == NULL) {
            struct TreeNode *l = root->left;
            free(root);
            return l;
        }
        struct TreeNode *rm = root->right;
        while ((rm != NULL) && (rm->left != NULL))
            rm = rm->left;
        root->val = rm->val;
        root->right = deleteNode(root->right, rm->val);
    } else if (root->val > key) {
        root->left = deleteNode(root->left, key);
    } else {
        root->right = deleteNode(root->right, key);
    }
    return root; 
}
