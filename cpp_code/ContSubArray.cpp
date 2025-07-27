class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long res = 0;
        int c = 0;
        multiset<int> ms;
        for (int i = 0; i < nums.size(); ++ i) {
            ms.insert(nums[i]);
            while (*ms.rbegin() - *ms.begin() > 2) {
                auto t = ms.find(nums[c]);
                ms.erase(t);
                c ++;
            }
            res += i - c + 1;
        }
        return res;
    }
};
