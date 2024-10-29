class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0)
            return {};
        vector<string> vout;
        for (int i = 0; i < nums.size(); ++i) {
            int p = nums[i];
            while ((i + 1 < nums.size()) && (nums[i] == nums[i + 1] - 1))
                ++i;
            int q = nums[i];
            if (p == q)
                vout.push_back(to_string(p));
            else
                vout.push_back(to_string(p) + "->" + to_string(q));
        }
        return vout;
    }
};
