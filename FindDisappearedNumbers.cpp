class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> out;
        int n = nums.size();
        vector<bool> vb(n + 1);
        for (int i = 0; i < n; ++ i) {
            vb[nums[i]] = true;
        }
        for (int i = 1; i <= n; ++ i) {
            if (vb[i] == false)
                out.push_back(i);
        }
        return out;
    }
};
