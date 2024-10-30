class Solution {
public:
    void parenthesis(vector<string>& o, string& s, int l, int r, int sz) {
        if ((l == 0) && (r == 0)) {
            o.push_back(s);
            return;
        }
        if (l > 0) {
            s.push_back('(');
            parenthesis(o, s, l - 1, r, sz);
            s.pop_back();
        }
        if (l < r) {
            s.push_back(')');
            parenthesis(o, s, l, r - 1, sz);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> vs;
        string s;
        parenthesis(vs, s, n, n, n);
        return vs;
    }
};
