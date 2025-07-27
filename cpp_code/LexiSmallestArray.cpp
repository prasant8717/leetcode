class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> v(n);
        iota(v.begin(), v.end(), 0);
        sort(v.begin(), v.end(), [&](int i, int j) {
            return nums[i] < nums[j];
        });
        vector<int> out(n);
        for (int i = 0; i < n;) {
            int j = i + 1;
            while ((j < n) && 
                   (nums[v[j]] - nums[v[j - 1]] <= limit))
                ++ j;
            vector<int> vt(v.begin() + i, v.begin() + j);
            ranges::sort(vt);
            for (int k = i; k < j; ++ k) {
                out[vt[k - i]] = nums[v[k]];
            }
            i = j;
        }
        return out;
    }
};
