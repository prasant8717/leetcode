/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int traverse(struct TreeNode *r, int l, int h) {
    if (r == NULL)
        return 0;
    int t = r->val;
    int res = 0;
    if ((l <= t) && (t <= h))
        res = t;
    if (t > l)
        res += traverse(r->left, l, h);
    if (t < h)
        res += traverse(r->right, l, h);
    return res;
}
int rangeSumBST(struct TreeNode* root, int low, int high) {
    return traverse(root, low, high);
}
