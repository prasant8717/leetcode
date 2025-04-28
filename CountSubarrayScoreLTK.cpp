class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        vector<long long> v(n + 1);
        for (int i = 0; i < n; ++ i)
            v[i + 1] = v[i] + nums[i];
        long long res = 0;
        for (int i = 1; i <= n; ++ i) {
            int l = 0;
            int r = i;
            while (l < r) {
                int m = (l + r + 1) >> 1;
                if ((v[i] - v[i - m]) * m < k)
                    l = m;
                else
                    r = m - 1;
            }
            res += l;
        }
        return res;
    }
};
