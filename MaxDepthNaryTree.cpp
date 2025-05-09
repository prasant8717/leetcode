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
    int maxDepth(Node* root) {
        int d = 0;
        if(root != nullptr) {
            for(int i = 0; i < root->children.size(); ++ i) {
                int t = maxDepth(root->children[i]);
                if (t > d)
                    d = t;
            }
        } else {
            d = -1;
        }
        return 1 + d;
    }
};
