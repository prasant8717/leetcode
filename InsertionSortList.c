/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if ((head == NULL) || (head->next == NULL))
        return head;
    struct ListNode d = {0, NULL};
    struct ListNode *p = &d;
    while (head != NULL) {
        struct ListNode* t = head->next;
        if (p->val >= head->val)
            p = &d;
        while ((p->next != NULL) && (p->next->val < head->val))
            p = p->next;
        head->next = p->next;
        p->next = head;
        head = t;
    }
    return d.next;    
}
