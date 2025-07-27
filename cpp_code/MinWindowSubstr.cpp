class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> ch(128);
        int len  = t.length();
        int idx = -1;
        int min = s.length() + 1;
        for (int i = 0; i < len; ++ i) {
            ++ ch[t[i]];
        }
        for (int l = 0, r = 0; r < s.length(); ++ r) {
            if (-- ch[s[r]] >= 0)
                -- len;
            while (len == 0) {
                if (r - l + 1 < min) {
                    idx = l;
                    min = r - l + 1;
                }
                if (++ ch[s[l++]] > 0)
                    ++ len ;
            }
        }
        return idx == -1 ? "" : s.substr(idx, min);        
    }
};
