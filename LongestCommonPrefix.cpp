class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) {
            return strs[0];            
        }
        string out;
        int m = strs.size();
        int n = strs[0].length();
        for (int i = 0; i < n; ++ i) {
            char ch;
            int j = 1;
            for (; j < m; ++ j) {
                ch = strs[0][i];
                if ((strs[j].length() < i) || (ch != strs[j][i])) {
                    return out;
                }
            }
            if (j == m) {
                out += ch;
            }
        }
        return out;
    }
};
