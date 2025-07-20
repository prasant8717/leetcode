class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k, vector<int>(k));
        for (int i = 0;  i < nums.size(); ++ i)
            for (int j = 0; j < k; ++ j)
                dp[nums[i] % k][j] = dp[j][nums[i] % k] + 1;
        return accumulate(dp.begin(), dp.end(), 0,
            [](int a, vector<int>& r) {
            return max(a, ranges::max(r));
        });
    }
};
