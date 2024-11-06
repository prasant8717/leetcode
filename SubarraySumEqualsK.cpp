class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map{{0, 1}};
        int res = 0;
        long long sum = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            sum += nums[i];
            res += map[sum - k];
            ++ map[sum];
        }
        return res;
    }
};
