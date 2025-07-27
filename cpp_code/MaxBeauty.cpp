class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        ranges::sort(nums);
        int res = 0;
        int n = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            while ((nums[i] - nums[n]) > (k << 1))
                ++ n;
            int t = i - n + 1;
            if (res < t)
                res = t;
        }
        return res;
    }
};
