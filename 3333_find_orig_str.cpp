class Solution {
private:
    static constexpr int m = 1'000'000'007;
    vector<int> form(string& s) {
        vector<int> vi;
        int k = 1;
        for (int i = 1; i < s.length(); ++ i)
            if (s[i] == s[i - 1]) {
                ++ k;
            } else {
                vi.push_back(k);
                k = 1;
            }
        vi.push_back(k);
        return vi;
    }

public:
    int possibleStringCount(string word, int k) {
        vector<int> vi = form(word);
        int t = accumulate(vi.begin(), vi.end(), 1L,
                   [](long long l, int n) { return l * n % m; });
        if (k <= vi.size())
            return t;
        vector<int> v(k);
        v[0] = 1;
        for (int i = 0; i < vi.size(); ++ i) {
            vector<int> vn(k);
            int a = 0;
            int b = vi[i];
            for (int j = i; j < k; ++ j) {
                vn[j] = (vn[j] + a) % m;
                a = (a + v[j]) % m;
                if (j >= b)
                    a = (a - v[j - b] + m) % m;
            }
            v = std::move(vn);
        }
        int c = accumulate(v.begin(), v.end(), 0,
                   [](int i, int c) { return (i + c) % m; });
        return (t - c + m) % m;
    }
};
