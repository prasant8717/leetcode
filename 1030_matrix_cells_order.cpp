class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> out;
        queue<pair<int, int>> qp{{{rCenter, cCenter}}};
        vector<vector<int>> vs(rows, vector<int>(cols));
        vs[rCenter][cCenter] = true;
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (qp.empty() == 0) {
            auto [i, j] = qp.front();
            qp.pop();
            out.push_back({i, j});
            for (auto& [dx, dy] : dir) {
                int x = i + dx;
                int y = j + dy;
                if ((x < 0) || (x == rows) || (y < 0) || (y == cols))
                    continue;
                if (vs[x][y] != 0)
                    continue;
                vs[x][y] = true;
                qp.emplace(x, y);
            }
        }
        return out;
    }
};
