class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n - 2; ++ i) {
            int t = nums[i] + nums[i + 2];
            if ((2 * t) == nums[i + 1])
                ++ res;
        }
        return res;
    }
};
