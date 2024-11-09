/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void recover(struct TreeNode *root, struct TreeNode **first, struct TreeNode **second, struct TreeNode **prev) {
    if (root == NULL)
        return;
    recover(root->left, first, second, prev);
    if ((*prev != NULL) && ((*prev)->val > root->val)) {
        if (*first == NULL)
            *first = *prev;
        *second = root;
    }
    *prev = root;
    recover(root->right, first, second, prev);
}
void recoverTree(struct TreeNode* root) {
    struct TreeNode* prev = NULL;
    struct TreeNode* first = NULL;
    struct TreeNode* second = NULL;
    recover(root, &first, &second, &prev);
    int tmp = first->val;
    first->val = second->val;
    second->val = tmp;
}
