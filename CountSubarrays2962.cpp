class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int m = *max_element(nums.begin(), nums.end());
        long long res = 0;
        int c = 0;
        int d = 0;
        for (int i = 0; i < n; ++ i) {
            while ((d < n) && (c < k))
                c += (nums[d ++] == m);
            if (c < k)
                break;
            res += n - d + 1;
            c -= (nums[i] == m);
        }
        return res;
    }
};
