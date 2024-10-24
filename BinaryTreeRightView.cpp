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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> out;
        int lvl = 0;
        while (root) {
            if (root->right) {
                TreeNode *p = root->right; 
                int b = 1; 
                while (p->left != nullptr && p->left != root) {
                    p = p->left;
                    b++;
                }
                if (p->left == nullptr) {
                    if (out.size() == lvl) {
                        out.push_back(root->val);
                    }
                    p->left = root;
                    root = root->right;
                    lvl++;  
                } else {  
                    p->left = nullptr;
                    root = root->left;
                    lvl -= b;  
                }
            } else {
                if (out.size() == lvl) {
                    out.push_back(root->val);
                }
                root = root->left;
                lvl++;  
            }
        }
        return out;        
    }
};
