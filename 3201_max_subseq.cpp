class Solution {
public:
    int maximumLength(vector<int>& nums) {
        vector<vector<int>> dp(2, vector<int>(2));
        for (int i = 0;  i < nums.size(); ++ i)
            for (int j = 0; j < 2; ++ j)
                dp[nums[i] % 2][j] = dp[j][nums[i] % 2] + 1;
        return accumulate(dp.begin(), dp.end(), 0,
            [](int a, vector<int>& r) {
            return max(a, ranges::max(r));
        });
    }
};
