/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    if (root->right == NULL)
        return 1 + minDepth(root->left);
    if (root->left == NULL)
        return 1 + minDepth(root->right);
    int res = 1;
    int t1 = minDepth(root->left);
    int t2 = minDepth(root->right);
    if (t1 > t2)
        res += t2;
    else
        res += t1;
    return res;
}
