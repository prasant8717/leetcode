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
    vector<TreeNode*> generate(int l, int h) {
        if (l > h)
            return {nullptr};
        vector<TreeNode*> out;
        for (int i = l; i <= h; ++ i) {
            vector<TreeNode*> tmp1 = generate(l, i - 1);
            for (int j = 0; j < tmp1.size(); ++ j) {
                vector<TreeNode*> tmp2 = generate(i + 1, h);
                for (int k = 0; k < tmp2.size(); ++ k) {
                    out.push_back(new TreeNode(i));
                    out.back()->left = tmp1[j];
                    out.back()->right = tmp2[k];
                }
            }
        }
        return out;
    }
    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
};
