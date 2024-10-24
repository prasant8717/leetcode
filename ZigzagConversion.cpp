class Solution {
public:
    string convert(string s, int numRows) {
        string out;
        vector<vector<char>> subs(numRows);
        int i = 0;
        int d = (numRows == 1) - 1;
        for (int j = 0; j < s.size(); ++ j) {
            subs[i].push_back(s[j]);
            if ((i == 0) || (i == numRows - 1))
                d *= -1;
            i += d;
        }
        for (int j = 0; j < subs.size(); ++ j) {
            for (int k = 0; k < subs[j].size(); ++ k) {
                out += subs[j][k];
            }
        }
        return out;        
    }
};
