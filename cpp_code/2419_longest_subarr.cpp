class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0;
        int idx = 0;
        int l = 0;
        for (int i = 0; i < nums.size(); ++ i)
            if (nums[i] == nums[idx]) {
                ++ l;
                if (res < l)
                    res = l;
            } else if (nums[i] > nums[idx]) {
                idx = i;
                l = 1;
                res = 1;
            } else {
                l = 0;
            }
        return res;
    }
};
