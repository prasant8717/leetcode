class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        ranges::sort(nums);
        int res = 1;
        int t = nums[0];
        for (int i = 0; i < nums.size(); ++ i) {
            if (nums[i] - t > k) {
                t = nums[i];
                res ++;
            }
        }
        return res;
    }
};
