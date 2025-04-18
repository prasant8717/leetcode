class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<int> vf;
        vector<int> vn(cells.size());
        for (int k = 0; n -- > 0; ++ k) {
            for (int i = 1; i < cells.size() - 1; ++ i)
                if (cells[i - 1] == cells[i + 1])
                    vn[i] = 1;
                else
                    vn[i] = 0;
            if (k == 0)
                vf = vn;
            else if (vn == vf)
                n %= k;
            cells = vn;
        }
        return cells;
    }
};
