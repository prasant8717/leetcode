class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> out;
        for (int i = 0; i < 12; ++ i) {
            for (int j = 0; j < 60; ++ j) {
                int b1 = 0;
                int t = i;
                while (t) {
                    ++ b1;
                    t = t & (t - 1);
                }
                int b2 = 0;
                t = j;
                while (t) {
                    ++ b1;
                    t = t & (t - 1);
                }
                if (b1 + b2 == turnedOn) {
                    string s = to_string(i) + ":";
                    if (j < 10)
                        s += "0";
                    s += to_string(j);
                    out.push_back(s);
                }
            }
        }
        return out;
    }
};
