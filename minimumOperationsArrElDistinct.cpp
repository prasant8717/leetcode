class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> us;
        for (int i = nums.size() - 1; i >= 0; -- i) {
            if (us.contains(nums[i]))
                return (i / 3) + 1;
            us.insert(nums[i]);
        }
        return 0;
    }
};
