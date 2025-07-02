class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> um;
        int res = 0;
        for (int i = 0;  i < nums.size(); ++ i)
            ++ um[nums[i]];
        for (auto [n, c] : um) {
            auto it = um.find(n + 1);
            if (it != um.cend()) {
                int t = c + it->second;
                if (res < t)
                    res = t;
            }
        }
        return res;
    }
};
