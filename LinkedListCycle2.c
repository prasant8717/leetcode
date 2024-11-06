/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *p1 = head;
    struct ListNode *p2 = head;
    while ((p2 != NULL) && (p2->next != NULL)) {
        p1 = p1->next;
        p2 = p2->next->next;
        if (p1 == p2) {
            p1 = head;
            while (p1 != p2) {
                p1 = p1->next;
                p2 = p2->next;
            }
            return p2;
        }
    }
    return NULL;
}
