class MPoint {
public:
    MPoint(int n) {
        p = vector<int>(n);
        sz = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }
    bool join(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py)
            return false;
        if (sz[px] > sz[py]) {
            p[py] = px;
            sz[px] += sz[py];
        } else {
            p[px] = py;
            sz[py] += sz[px];
        }
        return true;
    }
    int find(int a) {
        if (p[a] != a)
            p[a] = find(p[a]);
        return p[a];
    }
private:
    vector<int> p;
    vector<int> sz;
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        MPoint mp(n);
        int res = 0;
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < i; ++ j)
                if ((stones[i][0] == stones[j][0]) ||
                    (stones[i][1] == stones[j][1]))
                    res += mp.join(i, j);
        return res;
    }
};
