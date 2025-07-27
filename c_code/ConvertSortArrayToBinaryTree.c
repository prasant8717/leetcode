/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *add_link(int *nums, int left, int right) {
    if (left > right) {
        return NULL;
    }
    struct TreeNode *tmp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    int val = (left + right) / 2;
    tmp->left = add_link(nums, left, val - 1);
    tmp->val = nums[val];
    tmp->right = add_link(nums, val + 1, right);
    return tmp;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return add_link(&nums[0], 0, numsSize - 1);
}
