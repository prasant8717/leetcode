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
    vector<int> largestValues(TreeNode* root) {
        vector<int> out;
        if (root == nullptr)
            return out;
        queue<TreeNode*> que{{root}};
        while (que.size() != 0) {
            int m = INT_MIN;
            for (int i = que.size(); i > 0; -- i) {
                TreeNode* t = que.front();
                que.pop();
                if (m < t->val)
                    m = t->val;
                if (t->left != 0)
                    que.push(t->left);
                if (t->right != 0)
                    que.push(t->right);
            }
            out.push_back(m);
        }
        return out;
    }
};
