class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> vc(n + 2, 1);
        for (int i = 0; i < n; ++ i)
            vc[i + 1] = nums[i];
        vector<vector<int>> vv(n + 2, vector<int>(n + 2, 0));
        for (int i = n - 1; i >= 0; -- i) {
            for (int j = i + 2; j <= n + 1; ++ j) {
                for (int k = i + 1; k < j; ++ k) {
                    int t = vc[i] * vc[j] * vc[k];
                    t += vv[i][k] + vv[k][j];
                    if (vv[i][j] < t)
                        vv[i][j] = t;
                }
            }
        }
        return vv[0][n + 1];
    }
};
