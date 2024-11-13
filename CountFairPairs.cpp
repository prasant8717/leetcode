class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long cnt = 0;
        ranges::sort(nums);
        for (int i = 0; i < nums.size(); ++ i) {
            auto l = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            auto u = lower_bound(nums.begin() + i + 1, nums.end(), upper - nums[i] + 1);
            cnt += u - l;
        }
        return cnt;
    }
};
