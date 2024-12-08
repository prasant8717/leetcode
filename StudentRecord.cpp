class Solution {
public:
    bool checkRecord(string s) {
        int p = -1;
        int a = -1;
        int pc = 0;
        int ac = 0;
        for (int i = 0; i < s.size(); ++ i) {
            if (s[i] == 'A') {
                if ((a != -1) && (i == a + 1))
                    return false;
                else {
                    a = i;
                    ac ++;
                }
                if (ac == 2)
                    return false;
            } else if (s[i] == 'L') {
                if ((p != -1) && (i == p + 2) && (pc == 2))
                    return false;
                else {
                    if (pc == 0)
                        p = i;
                    pc ++;
                }
            } else {
                pc = 0;
            }
        }
        return true;
    }
};
