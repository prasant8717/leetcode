/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int diameter(struct TreeNode *h, int *l) {
    if (h == NULL)
        return 0;
    int lh = diameter(h->left, l);
    int rh = diameter(h->right, l);
    if (*l < (lh + rh))
        *l = lh + rh;
    return 1 + ((lh > rh) ? lh : rh);
}
int diameterOfBinaryTree(struct TreeNode* root) {
    int l = 0;
    diameter(root, &l);
    return l;
}
