class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int t = nums.size() - 2;
        while ((~t) && (nums[t] >= nums[t + 1])) {
            -- t;
        }
        if (~t) {
            for (int i = nums.size() - 1; i > t; -- i) {
                if (nums[i] > nums[t]) {
                    swap(nums[t], nums[i]);
                    break;
                }
            }
        }
        reverse(nums.begin() + t + 1, nums.end());
    }
};
