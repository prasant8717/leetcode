/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool traverse(struct TreeNode *r, int t) {
    if (r == NULL)
        return true;
    return (r->val == t) && traverse(r->left, t) &&
           traverse(r->right, t);
}
bool isUnivalTree(struct TreeNode* root) {
    return traverse(root, root->val);
}
