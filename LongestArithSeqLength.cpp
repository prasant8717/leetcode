class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        #define MAX 1000
        #define MAX_VAL 500
        int l = nums.size();
        vector<vector<int>> v(l, vector<int>(MAX + 1));
        int res = 0;
        for (int i = 1; i < l; ++ i) {
            for (int j = 0; j < i; ++ j) {
                int k = nums[i] - nums[j] + MAX_VAL;
                if (v[i][k] <= v[j][k])
                    v[i][k] = v[j][k] + 1;
                if (res <= v[i][k])
                    res = v[i][k];
            }
        }
        return res + 1;
    }
};
