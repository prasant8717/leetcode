class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int res = 1;
        int mi = 1;
        for (int i = 1; i < n; ++ i) {
            if (nums[i - 1] < nums[i]) {
                ++ mi;
                if (res < mi)
                    res = mi;
            } else {
                mi = 1;
            }
        }
        int md = 1;
        for (int i = 1; i < n; ++ i) {
            if (nums[i - 1] > nums[i]) {
                ++ md;
                if (res < md)
                    res = md;
            } else {
                md = 1;
            }
        }
        return res;
    }
};
