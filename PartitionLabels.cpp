class Solution {
public:
    vector<int> partitionLabels(string s) {
        int cnt[26] = {0};
        int l = s.length();
        for (int i = 0; i < l; ++ i) {
            cnt[s[i] - 'a'] = i;
        }
        vector<int> res;
        int max = 0;
        int j = 0;
        for (int i = 0; i < l; ++ i) {
            if (max < cnt[s[i] - 'a'])
                max = cnt[s[i] - 'a'];
            if (max == i) {
                res.push_back(i - j + 1);
                j = i + 1;
            }
        }
        return res;        
    }
};
