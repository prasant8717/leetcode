class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int c = 0;
        for (int i = 0; i < str1.size(); ++ i) {
            char ch = str1[i];
            if (ch == 'z')
                ch = 'a';
            else
                ch = ch + 1;
            if ((c < str2.size()) &&
                ((str2[c] == str1[i]) || (str2[c] == ch))) {
                ++ c;
            }
        }
        return c == str2.size();        
    }
};
