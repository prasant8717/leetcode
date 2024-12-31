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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int l = 0;
        ListNode *lt = head;
        while (lt != nullptr) {
            ++ l;
            lt = lt->next;
        }
        int lp = (l / k);
        int lr = (l % k);
        vector<ListNode *> vl(k, nullptr);
        lt = head;
        for (int i = 0; (i < k) && (lt != nullptr); ++ i) {
            vl[i] = lt;
            int m = lp;
            if (i < lr)
                ++ m;
            for (int j = 1; j < m; ++ j)
                lt = lt->next;
            ListNode *nxt = lt->next;
            lt->next = nullptr;
            lt = nxt;
        }
        return vl;
    }
};
