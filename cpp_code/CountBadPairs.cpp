class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> um;
        long long res = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            int t = i - nums[i];
            res += i - um[t];
            ++ um[t];
        }
        return res;
    }
};
