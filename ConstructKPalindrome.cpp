class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if (s.size() < k)
            return false;
        int c[26] = {0};
        for (int i = 0; i < n; ++ i)
            ++ c[s[i] - 'a'];
        int cnt = 0;
        for (int i = 0; i < 26; ++ i)
            cnt += c[i] & 1;
        return cnt <= k;        
    }
};
