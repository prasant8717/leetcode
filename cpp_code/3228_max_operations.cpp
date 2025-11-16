class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
        int res = 0;
        int k = 0;
        for (int i = 0; i < n; ++ i) {
            if (s[i] == '1')
                ++ k;
            else if ((i + 1 == n) || (s[i + 1] == '1'))
                res += k;
        }
        return res;
    }
};
