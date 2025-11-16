class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> si;
        si.push(0);
        int res = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            while ((si.empty() == 0) && (si.top() > nums[i]))
                si.pop();
            if ((si.empty() != 0) || (si.top() < nums[i])) {
                ++ res;
                si.push(nums[i]);
            }
        }
        return res;
    }
};
