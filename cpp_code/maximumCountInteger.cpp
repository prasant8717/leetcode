class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        int neg = -1;
        int r = n - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (nums[m] < 0) {
                neg = m;
                l = m + 1;
            } else
                r =  m - 1;
        }
        int pos = n;
        r = n - 1;
        l = 0;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (nums[m] > 0) {
                pos = m;
                r = m - 1;
            } else
                l = m + 1;
        }
        ++ neg;
        pos = n - pos;
        return (neg < pos) ? pos : neg;
    }
};
