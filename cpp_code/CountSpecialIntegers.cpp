class Solution {
public:
    int count(vector<vector<int>>& v, string& s,
              int i, int m, bool l, bool lm) {
        if (i >= s.size())
            return l ^ 1;
        if ((l == false) && (lm == false) && (v[i][m] != -1))
            return v[i][m];
        int t = 9;
        if (lm == true)
            t = s[i] - '0';
        int res = 0;
        for (int j = 0; j <= t; ++ j) {
            if ((l == true) && (j == 0))
                res += count(v, s, i + 1, m, true,
                            (lm == true) && (j == t));
            else if (((m >> j) & 1) ^ 1)
                res += count(v, s, i + 1, m | (1 << j), false, 
                            (lm == true) && (j == t));
        }
        if ((l == false) && (lm == false))
            v[i][m] = res;
        return res;
    }
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        int m = s.size();
        vector<vector<int>> v(m, vector<int>(1 << 10, -1));
        return count(v, s, 0, 0, true, true);        
    }
};
