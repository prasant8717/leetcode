/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node *, Node *> m;
    Node* copyRandomList(Node *head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (auto in = m.find(head); in != m.cend()) {
            return in->second;
        }
        Node* tmp = new Node(head->val);
        m[head] = tmp;
        tmp->next = copyRandomList(head->next);
        tmp->random = copyRandomList(head->random);
        return tmp;
    }
};
