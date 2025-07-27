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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> v;
        for (; head != nullptr; head = head->next)
            v.push_back(head->val);
        int n = v.size();
        vector<int> out(n);
        stack<int> stk;
        for (int i = n - 1; i >= 0; -- i) {
            while ((stk.empty() == 0) && (stk.top() <= v[i]))
                stk.pop();
            if (stk.empty() == 0)
                out[i] = stk.top();
            stk.push(v[i]);
        }
        return out;        
    }
};
