class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<bool> vb(101);
        int sum = 0;
        int mn = INT_MIN;
        for (int i = 0; i < nums.size(); ++ i) {
            int t = nums[i];
            if (mn < t)
                mn = t;
            if (nums[i] >= 0) {
                if (vb[t] == false) {
                    sum += t;
                    vb[t] = true;
                }
            }
        }
        if (mn < 0)
            sum = mn;
        return sum;
    }
};
