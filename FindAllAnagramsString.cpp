class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ls = s.size();
        int lp = p.size();
        vector<int> op;
        if (ls < lp) {
            return op;
        }
        vector<int> pc(26);
        for (int i = 0; i < lp; ++ i) {
            ++ pc[p[i] - 'a'];
        }
        vector<int> sc(26);
        for (int i = 0; i < lp - 1; ++ i) {
            ++ sc[s[i] - 'a'];
        }
        for (int i = lp - 1; i < ls; ++ i) {
            ++ sc[s[i] - 'a'];
            if (pc == sc) {
                op.push_back(i - lp + 1);
            }
            -- sc[s[i - lp + 1] - 'a'];
        }
        return op;        
    }
};
