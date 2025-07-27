class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> l;
        unordered_map<int, int> r;
        unordered_map<int, int> c;
        int n = nums.size();
        int d = 0;
        for (int i = 0; i < n; ++ i) {
            int t = nums[i];
            ++ c[t];
            if (d < c[t])
                d = c[t];
            if (l.count(t) == 0)
                l[t] = i;
            r[t] = i;
        }
        int res = 50001;
        for (int i = 0; i < n; ++ i) {
            int t = nums[i];
            if (c[t] == d) {
                int dl = r[t] - l[t] + 1;
                if (res > dl)
                    res = dl;
            }
        }
        return res;                
    }
};
