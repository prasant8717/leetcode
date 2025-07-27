class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        if (n < 4)
            return trees;
        ranges::sort(trees);
        vector<bool> vb(n);
        vector<int> vi(n + 10);
        int c = 1;
        for (int i = 1; i < n; ++ i) {
            while (c > 1) {
                auto v1 = trees[vi[c - 1]];
                auto v2 = trees[vi[c - 2]];
                auto v3 = trees[i];
                int t = (v2[0] - v1[0]) * (v3[1] - v2[1]);
                t -= (v2[1] - v1[1]) * (v3[0] - v2[0]);
                if (t < 0) {
                    c --;
                    vb[vi[c]] = false;
                } else {
                    break;
                }
            }
            vb[i] = true;
            vi[c] = i;
            ++ c;
        }
        int m = c;
        for (int i = n - 1; i >= 0; -- i) {
            if (vb[i] == true)
                continue;
            while (c > m) {
                auto& v1 = trees[vi[c - 1]];
                auto& v2 = trees[vi[c - 2]];
                auto& v3 = trees[i];
                int t = (v2[0] - v1[0]) * (v3[1] - v2[1]);
                t -= (v2[1] - v1[1]) * (v3[0] - v2[0]);
                if (t < 0)
                    c --;
                else
                    break;
            }
            vi[c] = i;
            ++ c;
        }
        vector<vector<int>> out;
        for (int i = 0; i < (c - 1); ++ i)
            out.push_back(trees[vi[i]]);
        return out;
    }
};
