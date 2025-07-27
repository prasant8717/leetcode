class Solution {
public:
    void smallest(int n, string& p, vector<bool>& v, string& t, string& r) {
        if (r != "")
            return;
        if (n == p.size() + 1) {
            r = t;
            return;
        }
        for (int i = 1; i < 10; ++ i) {
            if (v[i] == 0) {
                if (n && p[n - 1] == 'I' && t.back() - '0' >= i)
                    continue;
                if (n && p[n - 1] == 'D' && t.back() - '0' <= i) 
                    continue;
                v[i] = true;
                t += to_string(i);
                smallest(n + 1, p, v, t, r);
                t.pop_back();
                v[i] = false;
            }
        }
    }
    string smallestNumber(string pattern) {
        vector<bool> v(10, false);
        string t = "";
        string res = "";
        smallest(0, pattern, v, t, res);
        return res;
    }
};
