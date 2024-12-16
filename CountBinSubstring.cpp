class Solution {
public:
    int countBinarySubstrings(string s) {
        int c = 1;
        int p = 0;
        int res = 0;
        for(int i = 1; i < s.size(); i ++) {
            if(s[i] != s[i - 1]) {
                if (p > c)
                    res += c;
                else
                    res += p;
                p = c;
                c = 1;
            } else {
                ++ c;
            }
        }
        if (p < c)
            res += p;
        else
            res += c;
        return res;
    }
};
