class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            int m = i - nums[i];
            if (m < 0)
                m = 0;
            for (int j = m; j <= i; ++ j)
                sum += nums[j];
        }
        return sum;
    }
};
