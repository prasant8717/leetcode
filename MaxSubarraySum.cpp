class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int l = nums.size();
        long long max = 0;
        unordered_map<int, long long> um;
        long long sum = 0;
        for (int i = 0; i < k; ++ i) {
            um[nums[i]] ++;
            sum += nums[i];
        }
        if (um.size() == k)
            max = sum;
        for (int i = k; i < l; ++ i) {
            um[nums[i]] ++;
            -- um[nums[i - k]];
            if (um[nums[i - k]] == 0) {
                um.erase(nums[i - k]);
            }
            sum += nums[i] - nums[i - k];
            if (um.size() == k) {
                if (max < sum)
                    max = sum;
            }
        }
        return max;
    }
};
