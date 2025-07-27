class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ss = s + s;
        ss.erase(ss.length() - 1);
        return ss.find(s, 1) < s.size();
    }
};
