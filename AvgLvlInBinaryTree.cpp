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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> vout;
        queue<TreeNode*> que{{root}};
        while (que.empty() == 0) {
            long lvl_sum = 0;
            int sz = que.size();
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = que.front();
                que.pop();
                lvl_sum += node->val;
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            vout.push_back((double)lvl_sum / sz);
        }
        return vout;        
    }
};
