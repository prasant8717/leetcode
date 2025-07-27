class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0];
        int m = sum;
        for (int i = 1; i < nums.size(); ++ i) {
            if (nums[i - 1] < nums[i]) {
                sum += nums[i];
            } else {
                sum = nums[i];
            }
            if (m < sum)
                m = sum;
        }
        return m;
    }
};
