class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> out(n, false);
        int t = 0;
        for (int i = 0; i < n; ++ i) {
            t = ((t << 1) | nums[i]) % 5;
            if (t == 0)
                out[i] = true;
        }
        return out;
    }
};
