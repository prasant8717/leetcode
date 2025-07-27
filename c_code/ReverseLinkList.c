/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode* cur = head;
    struct ListNode *prev = NULL;
    int i;
    for (i = 1; i < left; i++) {
        prev = cur;
        cur = cur->next;
    }
    struct ListNode *ll = cur;
    struct ListNode *rr = NULL;
    struct ListNode *tmp = NULL;
    while (i <= right) {
        tmp = cur->next;
        cur->next = rr;
        rr = cur;
        cur = tmp;
        i++;
    }
    if (prev != NULL)
        prev->next = rr;
    else
        head = rr;
    ll->next = cur;
    return head;
}
