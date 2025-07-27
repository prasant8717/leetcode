class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int m = 0;
        long long md = 0;
        long long res = 0;
        for (int i= 0; i < nums.size(); ++ i) {
            long long l = md * nums[i];
            if (res < l)
                res = l;
            long long ll = (1LL * m) - nums[i];
            if (md < ll)
                md = ll;
            if (m < nums[i])
                m = nums[i];
        }
        return res;
    }
};
