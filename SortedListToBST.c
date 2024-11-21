/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedListToBST(struct ListNode* head) {
    if (head == NULL)
        return NULL;
    struct ListNode h = { 0, head };
    struct ListNode *s = &h;
    struct ListNode *f = &h;
    struct ListNode *p = NULL;
    while ((f != NULL) && (f->next != NULL)) {
        p = s;
        s = s->next;
        f = f->next->next;
    }
    p->next = NULL;
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = s->val;
    root->left = sortedListToBST(h.next);
    root->right = sortedListToBST(s->next);
    return root;
}
