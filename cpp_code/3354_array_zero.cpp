class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> vl(n);
        vector<int> vr(n);
        int res = 0;
        for (int i = 1; i < n; ++ i)
            vl[i] = vl[i - 1] + nums[i - 1];
        for (int i = n - 2; i >= 0; -- i)
            vr[i] = vr[i + 1] + nums[i + 1];
        for (int i = 0; i < n; ++ i) {
            if (nums[i] > 0)
                continue;
            if (vl[i] == vr[i])
                res += 2;
            int t = vl[i] - vr[i];
            if ((t == 1) || (t == -1))
                res += 1;
        }
        return res;
    }
};
