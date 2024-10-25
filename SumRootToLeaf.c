/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void traverse(struct TreeNode* root, int cur_sum, int *res) {
    if (root == NULL) {
        return;
    }
    if ((root->left == NULL) && (root->right == NULL)) {
        *res += (cur_sum * 10) + root->val;
        return;
    }
    traverse(root->left, cur_sum * 10 + root->val, res);
    traverse(root->right, cur_sum * 10 + root->val, res);
  }

int sumNumbers(struct TreeNode* root) {
    int res = 0;
    traverse(root, 0, &res);
    return res;
}
