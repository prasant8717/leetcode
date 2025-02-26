class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int m = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            int t = count(nums[i].begin(), nums[i].end(), '1');
            m |= 1 << t;
        }
        for (int i = 0; ; ++ i) {
            if (((m >> i) & 1) ^ 1) {
                return string(i, '1') + string(nums.size() - i, '0');
            }
        }
    }
};
