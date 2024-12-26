class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        ranges::sort(nums);
        for (int i = nums.size() - 1; i >= 2; -- i) {
            int t = nums[i - 1] + nums[i - 2];
            if (t > nums[i])
                return t + nums[i];
        }
        return 0;        
    }
};
