class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> us;
        int mi = INT_MAX;
        for (int i = 0; i < nums.size(); ++ i) {
            int x = nums[i];
            if (x < k)
                return -1;
            mi = min(mi, x);
            us.insert(x);
        }
        return us.size() - (mi == k);
    }
};
