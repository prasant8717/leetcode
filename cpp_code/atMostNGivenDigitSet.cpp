class Solution {
public:
    int generate(unordered_set<int>& us,
                 vector<int>& v,
                 string& s, int i, bool l, bool r) {
        int m = s.size();
        if (i >= m)
            if (l == true)
                return 0;
            else
                return 1;
        if ((l == false) && (r == false) && (v[i] != -1))
            return v[i];
        int t = s[i] - '0';
        if (r == false)
            t = 9;
        int res = 0;
        for (int j = 0; j <= t; ++ j)
            if ((j == 0) && (l == true))
                res += generate(us, v, s, i + 1, true, r && (j == t));
            else if (us.count(j) != 0)
                res += generate(us, v, s, i + 1, false, r && (j == t));
        if ((l == false) && (r == false))
            v[i] = res;
        return res;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        unordered_set<int> us;
        for (int i = 0; i < digits.size(); ++ i)
            us.insert(stoi(digits[i]));
        int m = s.size();
        vector<int> v(m, -1);
        return generate(us, v, s, 0, true, true);
    }
};
