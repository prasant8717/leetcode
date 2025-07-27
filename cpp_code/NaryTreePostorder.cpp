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
        for (int i = 0; i < r->children.size(); ++ i)
            traverse(r->children[i], v);
        v.push_back(r->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> out;
        traverse(root, out);
        return out;        
    }
};
