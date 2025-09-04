class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0;
        int k = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            if (nums[i] == 0)
                ++ k;
            if ((k > 1) && (nums[l ++] == 0))
                -- k;
        }
        return nums.size() - l - 1;
    }
};
