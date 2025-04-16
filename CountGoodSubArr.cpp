class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> ui;
        long long res = 0;
        long long c = 0;
        int i = 0;
        for (int j = 0; j < nums.size(); ++ j) {
            c += ui[nums[j]]++;
            while ((c - ui[nums[i]] + 1) >= k)
                c -= -- ui[nums[i ++]];
            if (c >= k)
                res += i + 1;
        }
        return res;
    }
};
