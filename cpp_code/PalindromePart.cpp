class Solution {
public:
    bool palendrome(string s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l ++;
            r --;
        }
        return true;
    }
    void part(string& s, int c, vector<string>& t, vector<vector<string>>& v) {
        if (c == s.length()) {
            v.push_back(t);
            return;
        }
        for (int i = c; i < s.length(); ++ i) {
            if (palendrome(s, c, i) == true) {
                t.push_back(s.substr(c, i - c + 1));
                part(s, i + 1, t, v);
                t.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> vs;
        vector<string> t;
        part(s, 0, t, vs);
        return vs;
    }
};
