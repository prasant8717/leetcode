class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string out;
        int l = 0;
        for (int i = s.length() - 1; i >= 0; -- i) {
            if (s[i] == '-')
                continue;
            if ((l > 0) && ((l % k) == 0))
                out += "-";
            out += toupper(s[i]);
            ++ l;
        }
        ranges::reverse(out);
        return out;
    }
};
