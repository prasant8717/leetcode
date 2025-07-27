class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> um;
        for (int i = 1; i < nums.size(); ++ i) {
            for (int j = 0; j < i; ++ j) {
                int t = nums[i] * nums[j];
                ++ um[t];
            }
        }
        int res = 0;
        for (auto& [_, t] : um) {
            res += t * (t - 1) / 2;
        }
        return res << 3;
    }
};
