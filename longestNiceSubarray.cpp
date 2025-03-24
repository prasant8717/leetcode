class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int res = 0;
        int m = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); ++ r) {
            while ((m & nums[r]) != 0) {
                m ^= nums[l];
                ++ l;
            }
            m |= nums[r];
            if (res < r - l + 1)
                res = r - l + 1;
        }
        return res;
    }
};
