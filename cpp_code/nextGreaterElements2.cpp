class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> out(n, -1);
        stack<int> stk;
        for (int i = (n << 1) - 1; i != 0; -- i) {
            int t = i % n;
            while ((stk.size() != 0) && (stk.top() <= nums[t]))
                stk.pop();
            if (stk.size() != 0)
                out[t] = stk.top();
            stk.push(nums[t]);
        }
        return out;
    }
};
