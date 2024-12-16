class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> out(m, vector<int>(n));
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                int s = 0;
                int c = 0;
                for (int a = i - 1; a <= i + 1; ++ a) {
                    for (int b = j - 1; b <= j + 1; ++ b) {
                        if ((a < 0) || (a >= m) ||
                            (b < 0) || (b >= n))
                            continue;
                        ++ c;
                        s += img[a][b];
                    }
                }
                out[i][j] = s / c;
            }
        }
        return out;        
    }
};
