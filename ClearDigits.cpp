class Solution {
public:
    string clearDigits(string s) {
        string ts;
        for (int i = 0; i < s.length(); ++ i) {
            if (isdigit(s[i]) != 0) {
                ts.pop_back();
            } else {
                ts.push_back(s[i]);
            }
        }
        return ts;
    }
};
