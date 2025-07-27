class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int ls = s.size();
        int lg = goal.size();
        if (ls != lg)
            return false;
        vector<int> c1(26);
        vector<int> c2(26);
        int d = 0;
        for (int i = 0; i < ls; ++ i) {
            ++ c1[s[i] - 'a'];
            ++ c2[goal[i] - 'a'];
            if (s[i] != goal[i])
                ++ d;
        }
        bool f = false;
        for (int i = 0; i < 26; ++i ) {
            if (c1[i] != c2[i])
                return false;
            if (c1[i] > 1)
                f = true;
        }
        if ((d == 2) || ((d == 0) && (f == true)))
            return true;
        else
            return false;
    }
};
