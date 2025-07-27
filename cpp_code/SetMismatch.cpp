class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int sum = (1 + n) * n / 2;
        unordered_set<int> us(nums.begin(), nums.end());
        int usum = 0;
        for (int i : us) {
            usum += i;
        }
        int tsum = 0;
        for (int i = 0; i < n; ++ i) {
            tsum += nums[i];
        }
        return {tsum - usum, sum - usum};        
    }
};
