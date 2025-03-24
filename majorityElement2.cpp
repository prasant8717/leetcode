class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0;
        int c2 = 0;
        int n1 = 0;
        int n2 = 1;
        for (int i = 0; i < nums.size(); ++ i) {
            int t = nums[i];
            if (t == n1)
                ++ c1;
            else if (t == n2)
                ++ c2;
            else if (c1 == 0) {
                n1 = t;
                ++ c1;
            } else if (c2 == 0) {
                n2 = t;
                ++ c2;
            } else {
                -- c1;
                -- c2;
            }
        }
        vector<int> out;
        if (ranges::count(nums, n1) > nums.size() / 3)
            out.push_back(n1);
        if (ranges::count(nums, n2) > nums.size() / 3)
            out.push_back(n2);
        return out;
    }
};
