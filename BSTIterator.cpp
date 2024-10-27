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
class BSTIterator {
public:
    vector<int> v;
    int idx;
    BSTIterator(TreeNode* root) {
        idx = 0;
        traverse(root);
    }
    
    int next() {
        return v[idx ++];
    }
    
    bool hasNext() {
        return idx < v.size();
    }

    void traverse(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        traverse(root->left);
        v.push_back(root->val);
        traverse(root->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
