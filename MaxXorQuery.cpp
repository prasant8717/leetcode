class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> out;
        int x = 0;
        for (int j = 0; j < nums.size(); ++ j)
            x ^= nums[j];
        while (nums.empty() == 0) {
            int k = 0;
            for (int i = maximumBit - 1; i >= 0; -- i) {
                if (((x >> i) & 1) == 0) {
                    k |= 1 << i;
                }
            }
            out.push_back(k);
            x ^= nums[nums.size() - 1];
            nums.pop_back();
        }
        return out;
    }
};
