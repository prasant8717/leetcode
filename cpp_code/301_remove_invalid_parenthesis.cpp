class Solution {
private:
    void rem(string& s, int i, int l, int r,
        int lc, int rc, string t, unordered_set<string>& us) {
        int n = s.size();
        if (i == n) {
            if (l == 0 && r == 0) {
                us.insert(t);
            }
            return;
        }
        if (n - i < l + r || lc < rc) {
            return;
        }
        if (s[i] == '(' && l) {
            rem(s, i + 1, l - 1, r, lc, rc, t, us);
        }
        if (s[i] == ')' && r) {
            rem(s, i + 1, l, r - 1, lc, rc, t, us);
        }
        int x = s[i] == '(' ? 1 : 0;
        int y = s[i] == ')' ? 1 : 0;
        rem(s, i + 1, l, r, lc + x, rc + y, t + s[i], us);
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> us;
        int l = 0;
        int r = 0;
        for (int i = 0; i < s.size(); ++ i) {
            if (s[i] == '(') {
                ++ l;
            } else if (s[i] == ')') {
                if (l) {
                    -- l;
                } else {
                    ++ r;
                }
            }
        }
        rem(s, 0, l, r, 0, 0, "", us);
        return vector<string>(us.begin(), us.end());
    }
};
