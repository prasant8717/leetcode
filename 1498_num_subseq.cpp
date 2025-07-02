class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        ranges::sort(nums);
        int res = 0;
        int mod = 1e9 + 7;
        int n = nums.size();
        int v[n + 1];
        v[0] = 1;
        for (int i = 1; i <= n; ++ i) {
            v[i] = (v[i - 1] << 1) % mod;
        }
        for (int i = 0; i < n; ++ i) {
            if ((nums[i] << 1) > target) {
                break;
            }
            int j = upper_bound(nums.begin() + i + 1, nums.end(), target - nums[i]) - nums.begin() - 1;
            res = (res + v[j - i]) % mod;
        }
        return res;
    }
};
