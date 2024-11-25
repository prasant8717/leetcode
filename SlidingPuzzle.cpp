class Solution {
public:
    struct my_hash {
        size_t operator()(const vector<int>& v) const {
            hash<int> hasher;
            size_t seed = 0;
            for (int i = 0; i < v.size(); ++ i) {
                seed ^= hasher(v[i]) + 0x9e3779b9 +
                        (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };
    vector<int> getip(vector<vector<int>> b) {
        vector<int> vs;
        for (int i = 0; i < 2; ++ i)
            for (int j = 0; j < 3; ++ j)
                vs.push_back(b[i][j]);
        return vs;
    }
    vector<vector<int>> update(vector<vector<int>>& board) {
        vector<vector<int>> vvr;
        pair<int, int> p = getzero(board);
        int i = p.first;
        int j = p.second;
        vector<int> d = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; ++ k) {
            int r = i + d[k];
            int c = j + d[k + 1];
            if ((r >= 0) && (r < 2) && (c >= 0) && (c < 3)) {
                exchange(board, i, j, r, c);
                vvr.push_back(getip(board));
                exchange(board, i, j, r, c);
            }
        }
        return vvr;
    }
    void exchange(vector<vector<int>>& board, int i, int j, int r, int c) {
        int t = board[i][j];
        board[i][j] = board[r][c];
        board[r][c] = t;
    }
    pair<int, int> getzero(vector<vector<int>>& board) {
        for (int i = 0; i < 2; ++ i)
            for (int j = 0; j < 3; ++ j)
                if (board[i][j] == 0)
                    return {i, j};
        return {0, 0};
    }
    void query(vector<int> v, vector<vector<int>>& board) {
        for (int i = 0; i < 2; ++ i)
            for (int j = 0; j < 3; ++ j)
                board[i][j] = v[i * 3 + j];
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<int> vs = getip(board);
        vector<int> ve;
        for (int i = 1; i <= 5; ++ i)
            ve.push_back(i);
        ve.push_back(0);
        if (vs == ve)
            return 0;
        unordered_set<vector<int>, my_hash> us;
        us.insert(vs);
        queue<vector<int>> q{{vs}};
        int ret = 0;
        while (q.empty() == 0) {
            ++ ret;
            for (int i = q.size(); i > 0; -- i) {
                vector<int> vt = q.front();
                q.pop();
                query(vt, board);
                vector<vector<int>> vv = update(board);
                for (int j = 0; j < vv.size(); ++ j) {
                    vector<int> vi = vv[j];
                    if (vi == ve)
                        return ret;
                    if (us.count(vi) == 0) {
                        us.insert(vi);
                        q.push(vi);
                    }
                }
            }
        }
        return -1;        
    }
};
