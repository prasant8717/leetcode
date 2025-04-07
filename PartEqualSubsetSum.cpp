class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return false;
        int s = 0;
        for (int i = 0; i < n; ++ i)
            s += nums[i];
        if ((s % 2) == 0) {
            vector<vector<bool>> v(n + 1, vector<bool>((s >> 1) + 1, false));
            v[0][0] = true;
            for (int i = 1; i <= n; ++ i)
                for (int j = 0; j <= (s >> 1); ++ j)
                    v[i][j] = v[i - 1][j] || ((j >= nums[i - 1]) && v[i - 1][j - nums[i - 1]]);
            return v[n][s >> 1];
        }
        return false;        
    }
};
