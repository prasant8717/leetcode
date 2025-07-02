class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> vo(n + 1);
        for (int i = 0; i < n; ++ i) {
            vo[nums[i]] ++;
        }
        vector<int> out;
        for (int i = 1; i <= n; ++ i) {
            if (vo[i] == 2) {
                out.push_back(i);
            }
        }
        return out;
    }
};
