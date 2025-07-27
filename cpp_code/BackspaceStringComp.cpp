class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int ls = s.length();
        int lt = t.length();
        string ss;
        for (int i = 0; i < ls; ++ i)
            if (s[i] != '#')
                ss += s[i];
            else
                if (ss.size() != 0)
                    ss.erase(ss.size() - 1);
        string st;
        for (int i = 0; i < lt; ++ i)
            if (t[i] != '#')
                st += t[i];
            else
                if (st.size() != 0)
                    st.erase(st.size() - 1);
        return (ss == st);
    }
};
