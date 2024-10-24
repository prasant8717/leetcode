class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> vout;
        int min = ranges::lower_bound(nums, target) - nums.begin();
        if ((min == nums.size()) || (nums[min] != target))
        {
            vout.push_back(-1);
            vout.push_back(-1);
        } else {
            int max = ranges::upper_bound(nums, target) - nums.begin() - 1;
            vout.push_back(min);
            vout.push_back(max);
        }
        return vout;
    }
};
