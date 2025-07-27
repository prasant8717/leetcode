class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> us;
        int res = 0;
        int sm = 0;
        int i = 0;
        int j = 0;
        for (; i < nums.size(); ++ i) {
            while (us.insert(nums[i]).second == 0) {
                sm -= nums[j];
                us.erase(nums[j ++]);
            }
            sm += nums[i];
            if (res < sm)
                res = sm;
        }
        return res;
    }
};
