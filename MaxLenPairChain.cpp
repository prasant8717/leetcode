class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        ranges::sort(pairs, {}, [](vector<int>& v) { return v[1]; });
        int res = 0;
        int max = INT_MIN;
        for (int i = 0; i < pairs.size(); ++ i) {
            if (max < pairs[i][0]) {
                max = pairs[i][1];
                ++ res;
            }
        }
        return res;
    }
};
