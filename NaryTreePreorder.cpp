/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void traverse(Node* r, vector<int>& v) {
        if (r == nullptr)
            return;
        v.push_back(r->val);
        for (int i = 0; i < r->children.size(); ++ i)
            traverse(r->children[i], v);
    }
    vector<int> preorder(Node* root) {
        vector<int> out;
        traverse(root, out);
        return out;
    }
};
