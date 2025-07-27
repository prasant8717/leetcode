class Solution {
public:
    string makeFancyString(string s) {
        string out;
        char c = s[0];
        out += c;
        int cnt = 1;
        for (int i = 1; i < s.length(); ++ i) {
            if (s[i] == c)
                ++ cnt;
            else {
                c = s[i];
                cnt = 1;
            }
            if (cnt < 3)
                out += c;
        }
        return out;
    }
};
