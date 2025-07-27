/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if (head == NULL)
    {
        return NULL;
    }
    struct ListNode* odd = head;
    struct ListNode* even = head->next;
    struct ListNode* even_first = even;
    while(1)
    {
        if ((odd == NULL) || (even == NULL) || (even->next == NULL))
        {
            odd->next = even_first;
            break;
        }
        odd->next = even->next;
        odd = even->next;
        if (odd->next == NULL)
        {
            even->next = NULL;
            odd->next = even_first;
            break;
        }
        even->next = odd->next;
        even = odd->next;
    }
    return head;
}
