class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> um;
        int res = nums.size();
        for (int i = 0; i < nums.size(); ++ i)
            ++ um[((nums[i] % value) + value) % value];
        for (int i = 0; i < nums.size(); ++ i)
            if (-- um[i % value] < 0) {
                res = i;
                break;
            }
        return res;
    }
};
