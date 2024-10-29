class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream strm(s);
        unordered_map<string, int> sm;
        vector<int> ch(128);
        int i = 0;
        for (string ss; strm >> ss; ++ i) {
            if (i == pattern.length())
                return false;
            if (sm[ss] != ch[pattern[i]])
                return false;
            sm[ss] = i + 1;
            ch[pattern[i]] = i + 1;
        }
        return (i == pattern.length());        
    }
};
