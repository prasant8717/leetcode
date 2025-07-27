class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        unordered_map<int, int> umc;
        for (int i = 0; i < nums.size(); ++ i)
            ++ umc[nums[i]];
        for (int i = -100; (i < 0) && (k > 0); ++ i) {
            int t = umc[i];
            if (t != 0) {
                int m = t > k ? k : t;
                umc[i] -= m;
                umc[-i] += m;
                k -= m;
            }
        }
        if ((k & 1) && (umc[0] == 0)) {
            for (int i = 1; i <= 100; ++ i) {
                if (umc[i]) {
                    -- umc[i];
                    ++ umc[-i];
                    break;
                }
            }
        }
        int res = 0;
        for (auto& [i, j] : umc) {
            res += i * j;
        }
        return res;
    }
};
