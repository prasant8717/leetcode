class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int mx = 30;
        vector<int> out(nums.size(), 1);
        vector<int> vs(mx);
        for (int i = nums.size() - 1; i >= 0; --i)
            for (int j = 0; j < mx; ++ j) {
                if ((nums[i] >> j) & 1)
                    vs[j] = i;
                int t = vs[j] - i + 1;
                if (out[i] < t)
                    out[i] = t;
            }
        return out;
    }
};
