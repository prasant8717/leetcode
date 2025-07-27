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
    void set_next(Node* root) {
        if (root == nullptr) {
            return;
        }
        queue<Node *> que{{root}};
        while (que.empty() == 0) {
            int sz = que.size();
            for (int i = 0; i < sz; ++i) {
                Node* node = que.front();
                que.pop();
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);                
                if (i == sz - 1)
                    node->next = nullptr;
                else {
                    Node *tmp = que.front();
                    node->next = tmp;
                }
            }
        }
    }

    Node* connect(Node* root) {
        set_next(root);
        return root;
    }
};
