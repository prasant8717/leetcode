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
 private:
    TreeNode* recover(string& s, int d, int& i) {
        int n = 0;
        while (i + n < s.length() && s[i + n] == '-')
            ++ n;
        if (n != d)
            return nullptr;
        i += d;
        int t = i;
        while (i < s.length() && isdigit(s[i]))
            ++i;
        return new TreeNode(stoi(s.substr(t, i - t)),
                        recover(s, d + 1, i), recover(s, d + 1, i));
  }

public:
    TreeNode* recoverFromPreorder(string traversal) {
        int i = 0;
        return recover(traversal, 0, i);
    }
};
