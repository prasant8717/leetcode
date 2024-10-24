/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void get_path(struct TreeNode *root, int sum, long long csum, int *cnt) {
    if (root == NULL) {
        return;
    }
    csum = csum + root->val;
    if (csum == sum) {
        (*cnt) ++;
    }
    get_path(root->left, sum, csum, cnt);
    get_path(root->right, sum, csum, cnt);
}

void get_all_path(struct TreeNode* root, int sum, int* cnt) {
    if (root == NULL)
        return;
    get_path(root, sum, 0, cnt);
    get_all_path(root->left, sum, cnt);
    get_all_path(root->right, sum, cnt);
}

int pathSum(struct TreeNode* root, int targetSum) {
    int cnt  = 0;
    get_all_path(root, targetSum, &cnt);
    return cnt;
}
