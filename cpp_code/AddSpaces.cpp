class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string out;
        int ns = 0;
        for (int i = 0; i < s.size(); ++ i) {
            if ((ns < spaces.size()) && (i == spaces[ns])) {
                out += ' ';
                ++ ns;
            }
            out += s[i];
        }
        return out;
    }
};
