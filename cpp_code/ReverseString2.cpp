class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i += (k << 1)) {
            int t = (i + k) < n ? i + k : n;
            reverse(s.begin() + i, s.begin() + t);
        }
        return s;        
    }
};
