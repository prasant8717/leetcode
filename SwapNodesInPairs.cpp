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
    ListNode* swapPairs(ListNode* head) {
        if ((head == nullptr) || (head->next == nullptr))
            return head;
        ListNode* hn = swapPairs(head->next->next);
        ListNode* n = head->next;
        n->next = head;
        head->next = hn;
        return n;        
    }
};
