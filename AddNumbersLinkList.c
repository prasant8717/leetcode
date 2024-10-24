/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *result = NULL;
    struct ListNode *first = NULL;
    int carry = 0;
    int l1_last = 0;
    int l2_last = 0;
    while(1)
    {
        int tmp;
        if (l1 != NULL)
        {
            tmp = l1->val;
            l1 = l1->next;
        }
        else
        {
            tmp = 0;
            l1_last = 1;
        }
        if (l2 != NULL)
        {
            tmp += l2->val;
            l2 = l2->next;
        }
        else
        {
            l2_last = 1;
        }
        struct ListNode* temp_node;
        if (first == NULL)
        {
            first = (struct ListNode*)malloc(sizeof(struct ListNode));
            temp_node = first;           
        }
        else
        {
            temp_node = (struct ListNode*)malloc(sizeof(struct ListNode));
        }
        if ((l1_last == 1) && (l2_last == 1))
        {
            if (carry)
            {
                struct ListNode* node = result;
                while(node->next != NULL)
                {
                    node = node->next;
                }
                temp_node->val = carry;
                temp_node->next = NULL;
                 node->next = temp_node;
            }
            break;
        }
        tmp = tmp + carry;
        if (tmp / 10)
        {
            carry = 1;
            tmp = (tmp % 10);
        }
        else
        {
            carry = 0;
        }
        temp_node->val = tmp;
        temp_node->next = NULL;
        if (result == NULL)
        {
            result = temp_node;
        }
        else
        {
            struct ListNode* node = result;
            while(node->next != NULL)
            {
                node = node->next;
            }
            node->next = temp_node;
        }
    }
    return first;
}
