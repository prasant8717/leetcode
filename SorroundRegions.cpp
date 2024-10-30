class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        int d[5] = {-1, 0, 1, 0, -1};
        function<void(int, int)> regions = [&](int i, int j) {
            if ((i < 0) || (i >= r) ||
                (j < 0) || (j >= c) ||
                (board[i][j] != 'O')) {
                return;
            }
            board[i][j] = '.';
            for (int k = 0; k < 4; ++ k) {
                regions(i + d[k], j + d[k + 1]);
            }
        };
        for (int i = 0; i < r; ++ i) {
            regions(i, 0);
            regions(i, c - 1);
        }
        for (int j = 1; j < c - 1; ++ j) {
            regions(0, j);
            regions(r - 1, j);
        }
        for (int i = 0; i < r; ++ i) {
            for (int j = 0; j < c; ++ j) {
                if (board[i][j] == '.') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }        
    }
};
