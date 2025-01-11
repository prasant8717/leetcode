/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return root;
        queue<Node*> qr{{root}};
        while (qr.empty() == 0) {
            Node *p = nullptr;
            for (int t = qr.size(); (t != 0); -- t) {
                Node *q = qr.front();
                qr.pop();
                if (p != nullptr)
                    p->next = q;
                p = q;
                if (q->left)
                    qr.push(q->left);
                if (q->right)
                    qr.push(q->right);
            }
        }
        return root;        
    }
};
