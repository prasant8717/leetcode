class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min = INT_MAX;
        int sum = 0;
        int l = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            sum += nums[i];
            while (sum >= target) {
                if (min > (i - l + 1)) {
                    min = i - l + 1;
                }
                sum -= nums[l];
                ++ l;
            }
        }
        return min == INT_MAX ? 0 : min;        
    }
};
