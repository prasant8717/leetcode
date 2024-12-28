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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*, TreeNode*>> qp;
        qp.push({root, nullptr});
        int d1 = 0;
        int d2 = 0;
        TreeNode *t1 = nullptr;
        TreeNode *t2 = nullptr;
        for (int d = 0; qp.size() != 0; ++ d) {
            for (int n = qp.size(); n != 0; -- n) {
                auto [nd, pr] = qp.front();
                qp.pop();
                if (nd->val == x) {
                    d1 = d;
                    t1 = pr;
                } else if (nd->val == y) {
                    d2 = d;
                    t2 = pr;
                }
                if (nd->left)
                    qp.push({nd->left, nd});
                if (nd->right)
                    qp.push({nd->right, nd});
            }
        }
        return (d1 == d2) && (t1 != t2);        
    }
};
