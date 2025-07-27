class Solution {
public:
    string removeOuterParentheses(string s) {
        string out;
        int c = 0;
        for (int i = 0; i < s.length(); ++ i)
            if (s[i] == '(') {
                if (++ c > 1)
                    out += s[i];
            } else if (-- c > 0) {
                out += s[i];
            }
        return out;
    }
};
