class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> v(target + 1);
        v[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int j = 0; j < nums.size(); ++ j) {
                if ((i >= nums[j]) && (v[i - nums[j]] < INT_MAX - v[i])) {
                    v[i] += v[i - nums[j]];
                }
            }
        }
        return v[target];        
    }
};
