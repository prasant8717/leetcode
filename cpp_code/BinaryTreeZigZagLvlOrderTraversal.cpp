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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> vout;
        deque<TreeNode*> que{{root}};
        int alt = 0;
        while (que.empty() == 0) {
            vector<int> vlvl;
            int sz = que.size();
            for (int i = 0; i < sz; ++i) {
                if (alt == 0) {
                    TreeNode* node = que.front();
                    que.pop_front();
                    vlvl.push_back(node->val);
                    if (node->left)
                        que.push_back(node->left);
                    if (node->right)
                        que.push_back(node->right);
                } else {
                    TreeNode* node = que.back();
                    que.pop_back();
                    vlvl.push_back(node->val);
                    if (node->right)
                        que.push_front(node->right);
                    if (node->left)
                        que.push_front(node->left);
                }
            }
            vout.push_back(vlvl);
            alt ^= 1;
        }
        return vout;        
    }
};
