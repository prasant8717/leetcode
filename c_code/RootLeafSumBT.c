/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int pathsum(struct TreeNode *r, int t) {
    if (r == NULL)
        return 0;
    t = (t << 1) | r->val;
    if ((r->left == NULL) && (r->right == NULL))
        return t;
    return pathsum(r->left, t) + pathsum(r->right, t);
}
int sumRootToLeaf(struct TreeNode* root) {
    return pathsum(root, 0);
}
