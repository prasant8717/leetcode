class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;
        vector<int> v(3, -1);
        for (int i = 0; i < s.length(); ++i) {
            v[s[i] - 'a'] = i;
            int t = v[0];
            if (t > v[1])
                t = v[1];
            if (t > v[2])
                t = v[2];
            res += (t + 1);
        }
        return res;
    }
};
