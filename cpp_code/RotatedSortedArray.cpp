class Solution {
public:
    int findMin(vector<int>& nums) {
        ranges::sort(nums);
        return nums[0];
    }
};
