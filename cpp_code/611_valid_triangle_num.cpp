class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        ranges::sort(nums);
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n - 2; ++ i) {
            for (int j = i + 1; j < n - 1; ++ j) {
                int t = nums[i] + nums[j];
                int k = lower_bound(nums.begin() + j + 1, nums.end(), t) - nums.begin() - 1;
                res += k - j;
            }
        }
        return res;      
    }
};
