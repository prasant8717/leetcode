class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3)
            return {};
        vector<vector<int>> out;
        ranges::sort(nums);
        for (int i = 0; i + 2 < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                int s = nums[i] + nums[l] + nums[r];
                if (s == 0) {
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[l++]);
                    v.push_back(nums[r--]);
                    out.push_back(v);
                    while (l < r && nums[l] == nums[l - 1])
                        ++l;
                    while (l < r && nums[r] == nums[r + 1])
                        --r;
                } else if (s < 0) {
                    ++l;
                } else {
                    --r;
                }
            }
        }
        return out;
    }
};
