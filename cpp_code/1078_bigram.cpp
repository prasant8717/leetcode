class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        stringstream ss(text);
        vector<string> out;
        string s1;
        string s2;
        for (string s; ss >> s;) {
            if ((s1 == first) && (s2 == second))
                out.push_back(s);
            s1 = s2;
            s2 = s;
        }
        return out;
    }
};
