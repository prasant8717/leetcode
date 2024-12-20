class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> us;
        vector<string> mc = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
            "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        for (int i = 0; i < words.size(); ++ i) {
            string s;
            for (int j = 0; j < words[i].size(); ++ j)
                s += mc[words[i][j] - 'a'];
            us.insert(s);
        }
        return us.size();
    }
};
