/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    struct ListNode *f = head;
    struct ListNode *s = head;
    while ((f->next != NULL) && (f->next->next != NULL)) {
        s = s->next;
        f = f->next->next;
    }
    struct ListNode *c = s->next;
    s->next = NULL;
    struct ListNode *p = NULL;
    while (c != NULL) {
        struct ListNode *t = c->next;
        c->next = p;
        p = c;
        c = t;
    }
    c = head;
    while (p != NULL) {
        struct ListNode *t = p->next;
        p->next = c->next;
        c->next = p;
        c = p->next;
        p = t;
    }    
}
