class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector<int> vx = heights;
        ranges::sort(vx);
        int res = 0;
        for (int i = 0; i < n; ++ i)
            if (vx[i] != heights[i])
                ++ res;
        return res;
    }
};
