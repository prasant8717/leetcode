using tup = tuple<int, int, int>;
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int k = queries.size();
        vector<pair<int, int>> vp(k);
        for (int i = 0; i < k; ++ i)
            vp[i] = {queries[i], i};
        ranges::sort(vp);
        vector<int> out(k);
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<bool>> vb(r, vector<bool>(c, false));
        vb[0][0] = true;
        priority_queue<tup, vector<tup>, greater<tup>> pq;
        pq.push({grid[0][0], 0, 0});
        int cnt = 0;
        vector<int> vd = { -1, 0, 1, 0, -1 };
        for (int i = 0; i < vp.size(); ++ i) {
            int v = vp[i].first;
            k = vp[i].second;
            while ((pq.empty() == 0) && (get<0>(pq.top()) < v)) {
                auto [_, i, j] = pq.top();
                pq.pop();
                ++ cnt;
                for (int h = 0; h < 4; ++ h) {
                    int x = i + vd[h];
                    int y = j + vd[h + 1];
                    if ((x >= 0) && (x < r) &&
                        (y >= 0) && (y < c) && (vb[x][y] == false)) {
                        vb[x][y] = true;
                        pq.push({grid[x][y], x, y});
                    }
                }
            }
            out[k] = cnt;
        }
        return out;
    }
};
