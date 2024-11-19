class Solution {
public:
    int numDistinct(string s, string t) {
        int l = t.size();
        vector<unsigned int> v(l + 1);
        v[0] = 1;
        for (int i = 0; i < s.size(); ++ i) {
            for (int j = l; j > 0; -- j) {
                if (s[i] == t[j - 1]) {
                    v[j] += v[j - 1];
                }
            }
        }
        return v[l];        
    }
};
