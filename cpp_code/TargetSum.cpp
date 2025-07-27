class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sz = nums.size();
        int sum = 0;
        for (int i = 0; i < sz; ++ i)
            sum += nums[i];
        int d = (sum - target);
        if ((sum < target) || (d % 2))
            return 0;
        d = (d >> 1);
        vector<vector<int>> v(sz + 1, vector<int>(d + 1));
        v[0][0] = 1;
        for (int i = 1; i <= sz; ++ i) {
            for (int j = 0; j <= d; ++ j) {
                v[i][j] = v[i - 1][j];
                if (j >= nums[i - 1]) {
                    v[i][j] += v[i - 1][j - nums[i - 1]];
                }
            }
        }
        return v[sz][d];
    }
};
