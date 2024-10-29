class Solution {
public:
    void queen(int h, int v, int l, int r, int n, int& res) {
        if (h == n)
            res ++;
        else
            for (int j = 0; j < n; j ++) {
                int vm = 1 << j;
                int lm = 1 << (h + j);
                int rm = 1 << (n - h - 1 + j);
                if ((v & vm) || (l & lm) || (r & rm))
                    continue;
                queen(h + 1, v | vm, l | lm, r | rm, n, res);
            }
    }
    int totalNQueens(int n) {
        int res = 0;
        queen(0, 0, 0, 0, n, res);
        return res;        
    }
};
