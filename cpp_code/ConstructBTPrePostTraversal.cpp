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
    TreeNode* construct(unordered_map<int, int>& um,
                        vector<int>& p, int a, int b, int c, int d) {
        if (a > b)
            return nullptr;
        TreeNode* r = new TreeNode(p[a]);
        if (a == b)
            return r;
        int i = um[p[a + 1]];
        int m = i - c + 1;
        r->left = construct(um, p, a + 1, a + m, c, i);
        r->right = construct(um, p, a + m + 1, b, i + 1, d - 1);
        return r;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> um;
        int n = postorder.size();
        for (int i = 0; i < n; ++ i) {
            um[postorder[i]] = i;
        }
        return construct(um, preorder, 0, n - 1, 0, n - 1);
    }
};
