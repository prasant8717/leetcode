class Solution {
public:
    bool find_solution(vector<vector<char>>& board, int cn) {
        if (cn == 81)
            return true;
        int r = cn / 9;
        int c = cn % 9;
        if (board[r][c] != '.') {
            return find_solution(board, cn + 1);
        }
        for (char ch = '1'; ch <= '9'; ++ ch) {
            if (verify(board, r, c, ch) == true) {
                board[r][c] = ch;
                if (find_solution(board, cn + 1) == true)
                    return true;
                board[r][c] = '.';
            }
        }
        return false;
    }
    bool verify(vector<vector<char>>& board, int r, int c, char ch) {
        for (int i = 0; i < 9; ++i) {
            if ((board[i][c] == ch) || (board[r][i] == ch) ||
                (board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == ch))
                    return false;
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        find_solution(board, 0);
    }
};
