class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        for (int i = 0; i < n; ++ i) {
            int j = i;
            while ((j < n) && (s[j] != ' '))
                ++ j;
            for (int k = i; k < ((i + j) >> 1); ++ k) {
                char c = s[k];
                s[k] = s[i + j - k - 1];
                s[i + j - k - 1] = c;
            }
            i = j;
        }
        return s;        
    }
};
