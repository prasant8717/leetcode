class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> vc(128);
        int res = 0;
        for (int i = 0; i < s.size(); ++ i)
            ++ vc[s[i]];
        int b = 0;
        for (int i = 0; i < 128; ++ i)
            if (vc[i] % 2 == 0)
                res += vc[i];
            else {
                res += vc[i] - 1;
                b = 1;
            }
        return res + b;
    }
};
