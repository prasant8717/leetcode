class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ir = 0;
        int jr = 0;
        for (int i = 0; i < 8; ++ i)
            for (int j = 0; j < 8; ++ j)
                if (board[i][j] == 'R') {
                    ir = i;
                    jr = j;
                }
        int res = 0;
        vector<vector<int>> vt;
        vt.push_back({1, 0});
        vt.push_back({0, 1});
        vt.push_back({-1, 0});
        vt.push_back({0, -1});
        for (int i = 0; i < vt.size(); ++ i) {
            int j = ir + vt[i][0];
            int k = jr + vt[i][1];
            for (; ((0 <= j) && (j < 8)) &&
                   ((0 <= k) && (k < 8)); ) {
                if (board[j][k] == 'p')
                    ++ res;
                if (board[j][k] != '.')
                    break;
                j += vt[i][0];
                k += vt[i][1];
            }
        }
        return res;        
    }
};
