class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long s = 0;
        for (int i = 0; i < n; ++ i)
            s += nums[i];
        long long t = 0;
        int res = 0;
        for (int i = 0; i + 1 < n; ++ i) {
            t += nums[i];
            if (t >= s - t)
                res ++;
        }
        return res;
    }
};
