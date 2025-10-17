class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int res = 0;
        int inc = 1;
        int pinc = 0;
        for (int i = 1; i < nums.size(); ++ i) {
            if (nums[i] > nums[i - 1])
                ++ inc;
            else {
                pinc = inc;
                inc = 1;
            }
            if (res < (inc >> 1))
                res = (inc >> 1);
            int t = pinc < inc ? pinc : inc;
            if (res < t)
                res = t;
        }
        return res;
    }
};
