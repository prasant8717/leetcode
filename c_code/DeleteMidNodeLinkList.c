/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    struct ListNode* list = head;
    if (list->next == NULL)
    {
        free(list);
        return NULL;
    }
    else
    {
        if (list->next->next == NULL)
        {
            free(list->next);
            list->next = NULL;
            return list;
        }
    }
    int num_of_nodes = 0;
    while (list != NULL)
    {
        num_of_nodes ++;
        list = list->next;
    }
    int mid = (num_of_nodes / 2) - 1;
    int tmp = 0;
    list = head;
    while (list)
    {
        if (tmp == mid)
        {
            struct ListNode* new_list_prev = list;
            struct ListNode* del_node = list->next;
            if (del_node->next != NULL)
            {
                new_list_prev->next = del_node->next;
            }
            else
            {
                new_list_prev->next = NULL;
            }
            free(del_node);
            break;

        }
        tmp ++;
        list = list->next;
    }
    return head;
}
