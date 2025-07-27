class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0;
        for (int i = 0; i < word.size(); ++ i)
            if (isupper(word[i]))
                cnt ++;
        return ((cnt == 0) || (cnt == word.size()) ||
            ((cnt == 1) && (isupper(word[0]))));
    }
};
