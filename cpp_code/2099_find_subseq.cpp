class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> vi(n);
        ranges::iota(vi, 0);
        ranges::sort(vi, [&](int i, int j) { return nums[i] < nums[j]; });
        ranges::sort(vi.begin() + n - k, vi.end());
        vector<int> out(k);
        for (int i = 0; i < k; ++ i) {
            out[i] = nums[vi[n - k + i]];
        }
        return out;
    }
};
