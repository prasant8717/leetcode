class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long m = INT_MIN;
        for (int i = 0; i < n - 2; ++ i)
            for (int j = i + 1; j < n - 1; ++ j)
                for (int k = j + 1; k < n; ++ k) {
                    long long t = ((long long)nums[i] - nums[j]) * nums[k];
                    if (t > m)
                        m = t;
                }
        if (m < 0)
            return 0;
        else
            return m;
    }
};
