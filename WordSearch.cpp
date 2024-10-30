class Solution {
public:
    bool search(string& w, vector<vector<char>>& b, int r, int c, int l) {
        if ((r < 0) || (r == b.size())) {
            return false;
        }
        if ((c < 0) || (c == b[0].size())) {
            return false;
        }
        if ((b[r][c] != w[l]) || (b[r][c] == '*')) {
            return false;
        }
        if (l == w.length() - 1) {
            return true;
        }
        char ch = b[r][c];
        b[r][c] = '*';
        bool sts = search(w, b, r + 1, c, l + 1);
        sts = sts || search(w, b, r - 1, c, l + 1);
        sts = sts || search(w, b, r, c + 1, l + 1);
        sts = sts || search(w, b, r, c - 1, l + 1);
        b[r][c] = ch;
        return sts;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++ i) {
            for (int j = 0; j < board[0].size(); ++ j) {
                if (search(word, board, i, j, 0) == true) {
                    return true;
                }
            }
        }
        return false;
    }
};
