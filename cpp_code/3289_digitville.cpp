class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> out;
        int n = nums.size();
        vector<int> vc(nums.size() - 2);
        for (int i = 0; i < nums.size(); ++ i)
            if (++ vc[nums[i]] == 2)
                out.push_back(nums[i]);
        return out;
    }
};
