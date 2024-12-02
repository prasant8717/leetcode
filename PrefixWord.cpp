class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream is(sentence);
        string s;
        for (int i = 1; is >> s; ++ i) {
            if (s.find(searchWord) == 0) {
                return i;
            }
        }
        return -1;        
    }
};
