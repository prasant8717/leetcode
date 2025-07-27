class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int ls = s.length();
        if (ls < 2)
            res = ls;
        else {
            vector<bool> vb(256);
            int l = 0;
            int r = 0;
            while (r < ls) {
                while (vb[s[r]] == true) {
                    vb[s[l]] = false;
                    l ++;
                }
                vb[s[r]] = true;
                if (res < r -l + 1)
                    res = (r - l + 1);
                r ++;
            }
        }
        return res;
    }
};
