class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long ll = 1;
        int res = 0;
        for (int i = 0; ll <= n;) {
            if ((i < nums.size()) && (nums[i] <= ll)) {
                ll += nums[i ++];
            } else {
                ++ res;
                ll <<= 1;
            }
        }
        return res;
    }
};
