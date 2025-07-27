 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rev_sublist(struct ListNode *start, struct ListNode *end) {
    struct ListNode *prv = NULL;
    struct ListNode *cur = start;
    while (cur != end) {
        struct ListNode *nxt = cur->next;
        cur->next = prv;
        prv = cur;
        cur = nxt;
    }
    return prv;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (head == NULL) {
        return NULL;
    }
    struct ListNode *cur = head;
    for (int i = 0; i < k; ++i) {
        if (cur == NULL) {
            return head;
        }
        cur = cur->next;
    }
    struct ListNode *tmp = rev_sublist(head, cur);
    head->next = reverseKGroup(cur, k);
    return tmp;    
}
