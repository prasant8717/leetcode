class Solution {
public:
    bool doesAliceWin(string s) {
        string sv = "aeiou";
        for (int i = 0; i < s.length(); ++ i)
            if (sv.find(s[i]) != string::npos) {
                return true;
            }
        return false;
    }
};
