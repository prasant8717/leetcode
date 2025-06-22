class Solution {
private:
    vector<string> vs;
    void expr(string s, int h, int t, long pn, char po,
    string sp) {
        for (int i = h; i < s.size(); ++ i)
        {
            if (i > h && s[h] == '0')
                break;
            string cs = s.substr(h, i - h + 1);
            long cn = stol(cs);
            if (po == '-')
                cn = 0 - cn;
            else if (po == '*')
                cn *= pn;
            if (i == s.size() - 1)
            {
                if (cn == t)
                    vs.push_back(sp + cs);
                break;
            }
            expr(s, i + 1, t - cn, cn, '+', sp + cs + "+");
            expr(s, i + 1, t - cn, cn, '-', sp + cs + "-");
            expr(s, i + 1, t, cn, '*', sp + cs + "*");
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        expr(num, 0, target, 0, '+', "");
        return vs;
    }
};
