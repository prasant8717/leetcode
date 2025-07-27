class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> us;
        for (int i = 0; i < nums.size(); ++i) {
            if (!us.insert(nums[i]).second)
                return true;
            if (i >= k)
                us.erase(nums[i - k]);
        }
        return false;
    }
};
