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
    ListNode* sortList(ListNode* head) {
        if ((head == nullptr) || (head->next == nullptr)) {
            return head;
        }
        ListNode *n1 = head;
        ListNode *n2 = head->next;
        while ((n2 != nullptr) && (n2->next != nullptr)) {
            n1 = n1->next;
            n2 = n2->next->next;
        }
        ListNode *cur = n1->next;
        n1->next = nullptr;
        n1 = sortList(head);
        n2 = sortList(cur);
        ListNode *out = new ListNode();
        cur = out;
        while ((n1 != nullptr) && (n2 != nullptr)) {
            if (n1->val <= n2->val) {
                cur->next = n1;
                n1 = n1->next;
            } else {
                cur->next = n2;
                n2 = n2->next;
            }
            cur = cur->next;
        }
        cur->next = n1 != nullptr ? n1 : n2;
        return out->next;
    }
};
