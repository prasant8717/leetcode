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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return {};
        }
        if (lists.size() == 1) {
            return lists[0];
        }
        ListNode *out = new ListNode();
        ListNode *st = lists[0];
        ListNode *cur = out;
        for (int i = 1; i < lists.size(); ++ i) {
            ListNode *n1 = st;
            ListNode *n2 = lists[i];
            while ((n1 != nullptr) && (n2 != nullptr)) {
                if (n1->val <= n2->val) {
                    cur->next = n1;
                    n1 = n1->next;
                } else {
                    cur->next = n2;
                    n2 = n2->next;
                }
                cur = cur->next;
            }
            cur->next = n1 != nullptr ? n1 : n2;
            cur = out;
            st = out != nullptr ? out->next : nullptr;
        }
        return out->next;
    }
};
