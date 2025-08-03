class Solution {
private:
    void subset(vector<int>& nums, int i, int s,
                int& os, int& res) {
        if (i == nums.size()) {
            if (s == os)
                ++ res;
            return;
        }
        subset(nums, i + 1, s, os, res);
        subset(nums, i + 1, s | nums[i], os, res);
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        int os = accumulate(nums.begin(), nums.end(), 0, bit_or<>());
        int res = 0;
        subset(nums, 0, 0, os, res);
        return res;
    }
};
