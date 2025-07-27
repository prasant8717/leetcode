/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int level(struct TreeNode *r) {
    if (r == NULL)
        return 0;
    int ll = level(r->left);
    int rl = level(r->right);
    int t = ll < rl ? rl - ll : ll - rl;
    if ((ll == -1) || (rl == -1) || (t > 1))
        return -1;
    return 1 + (ll < rl ? rl : ll);
}
bool isBalanced(struct TreeNode* root) {
    return level(root) >= 0;
}
