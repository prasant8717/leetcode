/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> sl1;
        stack<ListNode*> sl2;
        while (l1 != nullptr) {
            sl1.push(l1);
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            sl2.push(l2);
            l2 = l2->next;
        }
        ListNode* l = nullptr;
        int c = 0;
        while ((c != 0) || (sl1.empty() == 0) || (sl2.empty() == 0)) {
            if (sl1.empty() == 0) {
                c += sl1.top()->val;
                sl1.pop();
            }
            if (sl2.empty() == 0) {
                c += sl2.top()->val;
                sl2.pop();
            }
            ListNode* n = new ListNode(c % 10);
            n->next = l;
            l = n;
            c /= 10;
        }
        return l;
    }
};
