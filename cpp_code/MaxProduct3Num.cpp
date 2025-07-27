class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        ranges::sort(nums);
        int n = nums.size();
        int mm = nums[n - 3] * nums[n - 2] * nums[n - 1];
        int lm = nums[n - 1] * nums[0] * nums[1];
        return (mm > lm) ? mm : lm;
    }
};
