class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> v(m, vector<int>(n));
        for (int i = 0; i < guards.size(); ++ i)
            v[guards[i][0]][guards[i][1]] = 2;
        for (int i = 0; i < walls.size(); ++ i)
            v[walls[i][0]][walls[i][1]] = 2;
        int dirs[5] = { -1, 0, 1, 0, -1 };
        for (int i = 0; i < guards.size(); ++ i) {
            for (int j = 0; j < 4; ++ j) {
                int t1 = guards[i][0];
                int t2 = guards[i][1];
                while ((t1 + dirs[j] >= 0) &&
                       (t1 + dirs[j] < m) &&
                       (t2 + dirs[j + 1] >= 0) &&
                       (t2 + dirs[j + 1] < n) &&
                       (v[t1 + dirs[j]][t2 + dirs[j + 1]] < 2)) {
                    t1 += dirs[j];
                    t2 += dirs[j + 1];
                    v[t1][t2] = 1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < v.size(); ++ i) {
            for (int j = 0; j < v[i].size(); ++ j)
                if (v[i][j] == 0)
                    res ++;
        }
        return res;
    }
};
