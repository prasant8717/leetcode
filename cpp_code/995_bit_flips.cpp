class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> v(n + 1);
        int res = 0;
        int t = 0;
        for (int i = 0; i < n; ++ i) {
            t += v[i];
            if (t % 2 == nums[i]) {
                if (i + k > n) {
                    return -1;
                }
                ++ v[i];
                -- v[i + k];
                ++ t;
                ++ res;
            }
        }
        return res;
    }
};
