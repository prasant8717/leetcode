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
    ListNode* rotateRight(ListNode* head, int k) {
        if ((head == nullptr) || (head->next == nullptr) || (k == 0)) {
            return head;
        }
        ListNode* tail;
        int len = 1;
        for (tail = head; tail->next != nullptr; tail = tail->next) {
            ++ len;
        }
        tail->next = head;
        int t = len - (k % len);
        for (int i = 0; i < t; ++ i) {
            tail = tail->next;
        }
        ListNode* out = tail->next;
        tail->next = nullptr;
        return out;
    }
};
