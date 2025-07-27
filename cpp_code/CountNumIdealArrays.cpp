class Solution {
public:
    int idealArrays(int n, int maxValue) {
        a = maxValue;
        b = n;
        v1 = vector<vector<int>>(a + 1, vector<int>(16, -1));
        v2 = vector<vector<int>>(b, vector<int>(16, 0));
        for (int i = 0; i < b; ++ i) {
            for (int j = 0; (j <= i) && (j < 16); ++ j) {
                if (j != 0)
                    v2[i][j] = (v2[i - 1][j] + v2[i - 1][j - 1]) % m;
                else
                    v2[i][j] = 1;
            }
        }
        int res = 0;
        for (int i = 1; i <= a; ++ i)
            res = (res + dfs(i, 1)) % m;
        return res;
    }
    int dfs(int i, int cnt) {
        if (v1[i][cnt] != -1)
            return v1[i][cnt];
        int res = v2[b - 1][cnt - 1];
        if (cnt < b)
            for (int k = 2; (k * i) <= a; ++ k)
                res = (res + dfs(k * i, cnt + 1)) % m;
        v1[i][cnt] = res;
        return res;
    }
private:
    vector<vector<int>> v1;
    vector<vector<int>> v2;
    int a;
    int b;
    int m = 1e9 + 7;
};
