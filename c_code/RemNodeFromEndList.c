/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *p1 = head;
    struct ListNode *p2;
    int idx = 0;
    while (idx < n) {
        p1 = p1->next;
        idx ++;
    }
    if (p1 == NULL) {
        p1 = head;
        if (p1->next != NULL) {
            p2 = p1->next;
            free(p1);
            return p2;
        }
        return NULL;
    }
    p2 = p1;
    p1 = head;
    struct ListNode *tmp;
    while(p2->next != NULL) {
        p2 = p2->next;
        p1 = p1->next;
    }
    if (n == 1) {
        p1->next = NULL;
    } else {
        tmp = p1->next;
        p1->next = tmp->next;
        free(tmp);
    }
    return head;
}
