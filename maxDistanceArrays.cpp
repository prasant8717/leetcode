class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m1 = arrays[0][0];
        int m2 = arrays[0][arrays[0].size() - 1];
        int res = 0;
        for (int i = 1; i < arrays.size(); ++ i) {
            int t1 = abs(arrays[i][0] - m2);
            int t2 = abs(arrays[i][arrays[i].size() - 1] - m1);
            res = max({res, t1, t2});
            m1 = min(m1, arrays[i][0]);
            m2 = max(m2, arrays[i][arrays[i].size() - 1]);
        }
        return res;
    }
};
