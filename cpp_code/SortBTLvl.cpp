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
    int lvl_swap(vector<int>& v) {
        int n = v.size();
        vector<int> vt(v.begin(), v.end());
        ranges::sort(vt);
        unordered_map<int, int> um;
        int res = 0;
        for (int i = 0; i < n; ++ i)
            um[vt[i]] = i;
        for (int i = 0; i < n; ++ i)
            v[i] = um[v[i]];
        for (int i = 0; i < n; ++ i) {
            while (v[i] != i) {
                int tmp = v[i];
                v[i] = v[tmp];
                v[tmp] = tmp;
                ++ res;
            }
        }
        return res;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> que{{root}};
        int res = 0;
        while (que.empty() == 0 ) {
            vector<int> v;
            for (int n = que.size(); n; -- n) {
                auto node = que.front();
                que.pop();
                v.push_back(node->val);
                if (node->left != 0)
                    que.push(node->left);
                if (node->right != 0)
                    que.push(node->right);
            }
            res += lvl_swap(v);
        }
        return res;        
    }
};
