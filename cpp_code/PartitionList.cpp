/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *left = nullptr;
        ListNode *right = nullptr;
        ListNode *hleft = nullptr;
        ListNode *hright = nullptr;
        for (; head != nullptr; head = head->next) {
            if (head->val < x) {
                if (left != nullptr) {
                    left->next = head;
                } else {
                    hleft = head;
                }
                left = head;
            } else {
                if (right != nullptr) {
                    right->next = head;
                } else {
                    hright = head;
                }
                right = head;
            }
        }
        if (right != nullptr) {
            right->next = nullptr;
        }
        if (left != nullptr) {
            left->next = hright;
        } else {
            hleft = hright;
        }
        return hleft;
    }
};
