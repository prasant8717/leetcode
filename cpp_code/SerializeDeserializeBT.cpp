/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "";
        queue<TreeNode*> q{{root}};
        string s;
        while (q.empty() == 0) {
            auto t = q.front();
            q.pop();
            if (t != nullptr) {
                s += to_string(t->val) + " ";
                q.push(t->left);
                q.push(t->right);
            } else
                s += "# ";
        }
        s.pop_back();
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "")
            return nullptr;
        stringstream ss(data);
        string s;
        ss >> s;
        TreeNode* r = new TreeNode(stoi(s));
        queue<TreeNode*> q{{r}};
        while (q.empty() == 0) {
            auto n = q.front();
            q.pop();
            ss >> s;
            if (s != "#") {
                n->left = new TreeNode(stoi(s));
                q.push(n->left);
            }
            ss >> s;
            if (s != "#") {
                n->right = new TreeNode(stoi(s));
                q.push(n->right);
            }
        }
        return r;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
