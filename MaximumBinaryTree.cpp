/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* construct(vector<int>& nums, int l, int r) {
        if (l > r)
            return nullptr;
        int c = l;
        for (int i = l; i <= r; ++ i) {
            if (nums[c] < nums[i]) {
                c = i;
            }
        }
        TreeNode* root = new TreeNode(nums[c]);
        root->left = construct(nums, l, c - 1);
        root->right = construct(nums, c + 1, r);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
       return construct(nums, 0, nums.size() - 1);
    }
};
