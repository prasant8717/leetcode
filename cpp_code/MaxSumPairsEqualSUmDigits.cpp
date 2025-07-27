class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int m = 81;
        vector<vector<int>> vc(m + 1);
        for (int i = 0; i < nums.size(); ++ i) {
            int s = 0;
            int n = nums[i];
            while (n > 0) {
                s += n % 10;
                n /= 10;
            }
            vc[s].push_back(nums[i]);
        }
        int res = -1;
        for (int i = 0; i < vc.size(); ++ i) {
            if (vc[i].size() < 2)
                continue;
            ranges::sort(vc[i], greater<>());
            int t = vc[i][0] + vc[i][1];
            if (res < t)
                res = t;
        }
        return res;
    }
};
