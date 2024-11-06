/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverse(struct ListNode *l) {
    struct ListNode *p = NULL;
    while (l != NULL) {
        struct ListNode *t = l->next;
        l->next = p;
        p = l;
        l = t;
    }
    return p;
}
bool isPalindrome(struct ListNode* head) {
    struct ListNode *s = head;
    struct ListNode *f = head;
    while ((f != NULL) && (f->next != NULL)) {
        s = s->next;
        f = f->next->next;
    }
    if (f != NULL) {
        s = s->next;
    }
    s = reverse(s);
    while (s != NULL) {
        if (s->val != head->val)
            return false;
        s = s->next;
        head = head->next;
    }
    return true;
}
