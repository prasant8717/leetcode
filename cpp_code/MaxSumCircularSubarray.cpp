class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = 0;
        int cmax = 0;
        int cmin = 0;
        int tmax = INT_MIN;
        int tmin = INT_MAX;

        for (int num : nums) {
            sum += num;
            cmax = max(cmax + num, num);
            cmin = min(cmin + num, num);
            tmax = max(tmax, cmax);
            tmin = min(tmin, cmin);
        }
        return tmax < 0 ? tmax : max(tmax, sum - tmin);        
    }
};
