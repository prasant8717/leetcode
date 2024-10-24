class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> us{nums.begin(), nums.end()};
        for (int i = 0; i < nums.size(); ++ i) {
            if (us.contains(nums[i] - 1))
                continue;
            int seq = 1;
            while (us.contains(++ nums[i])) {
                ++ seq;
            }
            res = max(res, seq);
        }
        return res;
    }
};
