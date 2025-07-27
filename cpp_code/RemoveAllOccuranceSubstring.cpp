class Solution {
public:
    string removeOccurrences(string s, string part) {
        int p = part.length();
        string res = "";
        while (true) {
            int t = s.find(part);
            if (t != string::npos) {
                s.erase(t, p);
                if (s.length() < p) {
                    res = s;
                    break;
                }
            } else {
                res = s;
                break;
            }
        }
        return res;
    }
};
