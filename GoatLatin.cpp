class Solution {
public:
    bool isVowel(char c) {
        string kVowels = "aeiouAEIOU";
        return kVowels.find(c) != string::npos;
    }
    string toGoatLatin(string sentence) {
        string out;
        istringstream stm(sentence);
        int i = 1;
        for (string s; stm >> s;) {
            if (i > 1)
                out += ' ';
            if (isVowel(s[0]))
                out += s;
            else
                out += s.substr(1) + s[0];
            out += "ma" + string(i ++, 'a');
        }
        return out;        
    }
};
