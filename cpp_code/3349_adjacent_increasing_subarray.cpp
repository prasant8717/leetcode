class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        bool sts = false;
        int pinc = 0;
        int inc = 1;
        for (int i = 1; i < nums.size(); ++ i) {
            if (nums[i] > nums[i - 1]) {
                ++ inc;
            } else {
                pinc = inc;
                inc = 1;
            }
            int t = pinc < inc ? pinc : inc;
            if (((inc >> 1) >= k) || (t >= k)) {
                sts = true;
                break;
            }
        }
        return sts;
    }
};
