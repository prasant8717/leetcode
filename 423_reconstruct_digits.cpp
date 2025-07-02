class Solution {
public:
    string originalDigits(string s) {
        vector<int> vc(26);
        for (int i = 0; i < s.size(); ++ i)
            ++ vc[s[i] - 'a'];
        vector<int> vn(10);
        vn[0] = vc['z' - 'a'];
        vn[2] = vc['w' - 'a'];
        vn[4] = vc['u' - 'a'];
        vn[6] = vc['x' - 'a'];
        vn[8] = vc['g' - 'a'];
        vn[3] = vc['h' - 'a'] - vn[8];
        vn[5] = vc['f' - 'a'] - vn[4];
        vn[7] = vc['s' - 'a'] - vn[6];
        vn[1] = vc['o' - 'a'] - vn[0] - vn[2] - vn[4];
        vn[9] = vc['i' - 'a'] - vn[5] - vn[6] - vn[8];
        string res;
        for (int i = 0; i < 10; ++ i)
            for (int j = 0; j < vn[i]; ++ j)
                res += char(i + '0');
        return res;
    }
};
