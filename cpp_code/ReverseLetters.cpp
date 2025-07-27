class Solution {
public:
    string reverseOnlyLetters(string s) {
        int sz = s.size();
        int l = 0;
        int r = sz - 1;
        while (l < r) {
            bool is_small_l = (s[l] <= 'z') && (s[l] >= 'a');
            bool is_cap_l = (s[l] <= 'Z') && (s[l] >= 'A');
            if ((is_small_l || is_cap_l) == false)
                ++ l;
            else {
                bool is_small_r = (s[r] <= 'z') && (s[r] >= 'a');
                bool is_cap_r = (s[r] <= 'Z') && (s[r] >= 'A');
                if ((is_small_r || is_cap_r) == false)
                    -- r;
                else {
                    char t = s[l];
                    s[l] = s[r];
                    s[r] = t;
                    ++ l;
                    -- r;
                }
            }
        }
        return s;
    }
};
