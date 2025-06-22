class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> vm(n);
        int res = 0;
        for (int i = 0; i < n; ++ i) {
            for (char& c : words[i]) {
                vm[i] |= 1 << (c - 'a');
            }
            for (int j = 0; j < i; ++ j) {
                if ((vm[i] & vm[j]) == 0) {
                    int t = (int) (words[i].size() * words[j].size());
                    if (res < t)
                        res = t;
                }
            }
        }
        return res;
    }
};
