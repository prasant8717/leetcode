class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        ranges::sort(nums);
        int res = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target)
                    return sum;
                if (abs((long long)sum - target) < abs((long long)res - target))
                    res = sum;
                if (sum > target)
                    -- k;
                else
                    ++ j;
            }
        }
        return res;        
    }
};
