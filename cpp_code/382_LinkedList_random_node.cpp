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
private:
    ListNode *root;

public:
    Solution(ListNode* head) {
        root = head;
    }
    
    int getRandom() {
        int res = -1;
        int i = 1;
        for (ListNode *l = root; l != nullptr; l = l->next) {
            if ((rand() % i) == 0)
                res = l->val;
            ++ i;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
