class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        ranges::sort(nums);
        int mx = INT_MIN;
        for (int i = 0; i < nums.size() - 1; i ++) {
            int t = nums[i + 1] - nums[i];
            if (mx < t)
                mx = t;
        }
        return mx;
    }
};
