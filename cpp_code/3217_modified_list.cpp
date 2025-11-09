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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> us(nums.begin(), nums.end());
        ListNode* ld = new ListNode(0, head);
        for (ListNode* ln = ld; ln->next != nullptr;)
            if (us.count(ln->next->val))
                ln->next = ln->next->next;
            else
                ln = ln->next;
        return ld->next;
    }
};
