class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = 0;
        char ch1 = 0;
        char ch2 = 0;
        for (int i = 0; i < s1.size(); ++ i) {
            char c1 = s1[i];
            char c2 = s2[i];
            if (c1 != c2) {
                ++ n;
                if ((n > 2) || ((n == 2) &&
                    ((c1 != ch2) || (c2 != ch1)))) {
                    return false;
                }
                ch1 = c1;
                ch2 = c2;
            }
        }
        return n != 1;
    }
};
