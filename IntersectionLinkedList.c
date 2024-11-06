/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if ((headA == NULL) || (headB == NULL))
        return NULL;
    struct ListNode *s = headA;
    struct ListNode *d = headB;
    while (s != NULL) {
        while (d != NULL) {
            if (s == d)
                return d;
            d = d->next;
        }
        s = s->next;
        d = headB;
    }
    return NULL;
}
