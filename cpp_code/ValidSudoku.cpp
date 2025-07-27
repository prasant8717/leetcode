class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> uss;
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;
                string str(1, board[i][j]);
                if (!uss.insert(str + "@row" + to_string(i)).second ||
                    !uss.insert(str + "@col" + to_string(j)).second ||
                    !uss.insert(str + "@box" + to_string(i / 3) + to_string(j / 3)).second)
                    return false;
            }
        return true;        
    }
};
