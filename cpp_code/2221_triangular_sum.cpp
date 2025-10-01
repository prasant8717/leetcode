class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        while (1) {
            if (n == 1)
                break;
            for (int i = 0; i < n - 1; ++ i) {
                nums[i] = nums[i] + nums[i + 1];
                if (nums[i] >= 10)
                    nums[i] %= 10;
            }
            -- n;
        }
        return nums[0];
    }
};
