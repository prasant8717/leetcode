class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int res = 0;
        for (int i = 0; i < n; ++ i) {
            string t = words[i];
            for (int j = i + 1; j < n; ++ j) {
                string t1 = words[j];
                if ((t1.find(t) == 0) &&
                    (t1.rfind(t) == t1.length() - t.length())) {
                    ++ res;
                }
            }
        }
        return res;
    }
};
