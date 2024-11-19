class Solution {
public:
    int steps(string& s, int i, int j, vector<vector<int>>& v) {
        if (i >= j)
            return 0;
        if (v[i][j] != 0)
            return v[i][j];
        int min = INT_MAX;
        if (s[i] == s[j]) {
            min = steps(s, i + 1, j - 1, v);
        } else {
            min = steps(s, i + 1, j, v);
            int t = steps(s, i, j - 1, v);
            if (min > t)
                min = t;
            min += 1;
        }
        v[i][j] = min;
        return min;
    };
    int minInsertions(string s) {
        int l = s.size();
        vector<vector<int>> v(l, vector<int>(l));
        return steps(s, 0, l - 1, v);
    }
};
