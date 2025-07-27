class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<bool> vr(m);
        vector<bool> vc(n);
        for (int i = 0; i < indices.size(); ++ i) {
            int r = indices[i][0];
            int c = indices[i][1];
            vr[r] = vr[r] ^ true;
            vc[c] = vc[c] ^ true;
        }
        int res = 0;
        for (int i = 0; i < m; ++ i)
            for (int j = 0; j < n; ++ j)
                res += vr[i] ^ vc[j];
        return res;
    }
};
