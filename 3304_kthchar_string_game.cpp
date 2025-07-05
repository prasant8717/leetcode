class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        int c = 1;
        for (int i = 0; i < k; ++ i) {
            string t = "";
            for (int j = 0; j < s.size(); ++ j) {
                char ch = s[j];
                if (s[j] == 'z')
                    ch = 'a';
                else
                    ch += 1;
                t += ch;
                ++ c;
                if (c == k) {
                    return ch;
                }
            }
            s += t;
        }
        return 'a';
    }
};
