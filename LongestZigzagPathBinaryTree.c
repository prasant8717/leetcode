/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void find_zigzag(struct TreeNode *root, int *cnt, int l, int r) {
    if (root == NULL) {
        return;
    }
    int tmp = r;
    if (tmp < l) {
        tmp = l;
    }
    if (*cnt < tmp) {
        *cnt = tmp;
    }
    if (root->left != NULL) {
        find_zigzag(root->left, cnt, r + 1, 0);
    }
    if (root->right != NULL) {
        find_zigzag(root->right, cnt, 0, l + 1);
    }
}
int longestZigZag(struct TreeNode* root) {
    int cnt = 0;
    find_zigzag(root, &cnt, 0, 0);
    return cnt;
}
