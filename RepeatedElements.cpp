class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> us;
        for (int i = 0; ; ++ i) {
            if (us.count(nums[i])) {
                return nums[i];
            }
            us.insert(nums[i]);
        }
    }
};
