class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> vtmp(10001);
        for (int i = 0; i < nums.size(); ++ i) {
            vtmp[nums[i]] += nums[i];
        }
        int a = 0;
        int b = vtmp[0];
        for (int i = 1; i < vtmp.size(); ++ i) {
            int c = vtmp[i] + a;
            if (c < b)
                c = b;
            a = b;
            b = c;
        }
        return b;
    }
};
