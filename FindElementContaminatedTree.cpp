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
class FindElements {
private:
    unordered_set<int> us;
    void search(TreeNode* r) {
        us.insert(r->val);
        if (r->left) {
            r->left->val = r->val * 2 + 1;
            search(r->left);
        }
        if (r->right) {
            r->right->val = r->val * 2 + 2;
            search(r->right);
        }
    }

public:
    FindElements(TreeNode* root) {
        root->val = 0;
        search(root);
    }
    
    bool find(int target) {
        return us.contains(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
