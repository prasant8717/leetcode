class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> cs(128);
        vector<int> ct(128);
        for (int i = 0; i < s.length(); ++ i) {
            if (cs[s[i]] != ct[t[i]])
                return false;
            cs[s[i]] = i + 1;
            ct[t[i]] = i + 1;
        }
        return true;        
    }
};
