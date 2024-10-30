class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int r = board.size();
        int c = board[0].size();
        for (int i = 0; i < r; ++ i) {
            for (int j = 0; j < c; ++ j) {
                int live = -board[i][j];
                for (int k = i - 1; k <= i + 1; ++ k) {
                    for (int l = j - 1; l <= j + 1; ++ l) {
                        if ((k >= 0) && (k < r) &&
                            (l >= 0) && (l < c) && board[k][l] > 0) {
                            ++ live;
                        }
                    }
                }
                if ((board[i][j] == 0) && (live == 3)) {
                    board[i][j] = -1;
                }
                if ((board[i][j] == 1) &&
                    ((live < 2) || (live > 3))) {
                    board[i][j] = 2;
                }
            }
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (board[i][j] == 2) {
                    board[i][j] = 0;
                } else if (board[i][j] == -1) {
                    board[i][j] = 1;
                }
            }
        }        
    }
};
