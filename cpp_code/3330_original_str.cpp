class Solution {
public:
    int possibleStringCount(string word) {
        int res = 1;
        char ch = word[0];
        for (int i = 1; i < word.size(); ++ i) {
            if (ch == word[i])
                ++ res;
            ch = word[i];
        }
        return res;
    }
};
