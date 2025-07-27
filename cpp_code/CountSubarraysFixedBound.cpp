class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0;
        int a = -1;
        int b = -1;
        int c = -1;
        for (int i = 0; i < nums.size(); ++ i) {
            if ((nums[i] < minK) || (nums[i] > maxK))
                c = i;
            if (nums[i] == minK)
                a = i;
            if (nums[i] == maxK)
                b = i;
            int t = a;
            if (t > b)
                t = b;
            int tt = t - c;
            if (tt > 0)
                res += tt;
        }
        return res;
    }
};
