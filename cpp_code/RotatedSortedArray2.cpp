class Solution {
public:
    bool search(vector<int>& nums, int target) {
        ranges::sort(nums);
        int l = 0;
        int r = nums.size();
        while (l < r) {
            int m = (l + r) >> 1;
            if (nums[m] == target)
                return true;
            if (nums[m] < target)
                l = m + 1;
            else
                r = m;
        }
        return false;
    }
};
