class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> ui;
        int d = 0;
        int c = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            int t = nums[i];
            ++ ui[t];
            if (ui[t] > c) {
                c = ui[t];
                d = t;
            }
        }
        int nc = 0;
        for (int i = 1; i <= nums.size(); ++ i) {
            if (nums[i - 1] == d) {
                ++ nc;
                if (((nc << 1) > i) &&
                    (((c - nc) << 1) > (nums.size() - i)))
                    return i - 1;
            }
        }
        return -1;
    }
};
