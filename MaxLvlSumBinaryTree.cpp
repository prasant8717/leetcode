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
    void max_level(TreeNode *root, int *lvl) {
	    if (root == nullptr)
		    return;
	    int out = INT_MIN;
	    queue<TreeNode *> q;
	    q.push(root);
        int lv = 0;
	    while (q.empty() == 0) {
		    int cnt = q.size();
		    int sum = 0;
            lv ++;
		    while (cnt--) {
			    TreeNode* tmp = q.front();
			    q.pop();
			    sum = sum + tmp->val;
			    if (tmp->left != NULL)
				    q.push(tmp->left);
			    if (tmp->right != NULL)
				    q.push(tmp->right);
		    }
		    if (out < sum) {
                out = sum;
                *lvl = lv;
            }
	    }
    }

    int maxLevelSum(TreeNode* root) {
        int lvl = 0;
        max_level(root, &lvl);
        return lvl;
    }
};
