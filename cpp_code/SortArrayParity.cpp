class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ve;
        vector<int> vo;
        int n = nums.size();
        for (int i = 0; i < n; ++ i) {
            if (nums[i] % 2 == 0)
                ve.push_back(nums[i]);
            else
                vo.push_back(nums[i]);
        }
        ve.insert(ve.end(), vo.begin(), vo.end());
        return ve;
    }
};
