/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int pairSum(struct ListNode* head) {
    int len = 0;
    struct ListNode* list = head;
    while (list != NULL)
    {
        len ++;
        list = list->next;
    }
    int *arr = (int *)malloc(sizeof(int) * len);
    struct ListNode* lst = head;
    int idx = 0;
    while (lst != NULL)
    {
        arr[idx] = lst->val;
        lst = lst->next;
        idx ++;
    }
    int max = 0;
    for (int i = 0; i < (len/2); ++ i)
    {
        int tmp = arr[i] + arr[len - i -1];
        if (max < tmp)
        {
            max = tmp;
        }
    }
    return max;
}
