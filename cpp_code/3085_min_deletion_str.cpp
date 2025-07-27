class Solution {
private:
    int fn(int t, vector<int>& v, int k) {
        int res = 0;
        for (int i : v) {
            if (i < t) {
                res += i;
            } else if (i > t + k) {
                res += i - t - k;
            }
        }
        return res;
    }
public:
    int minimumDeletions(string word, int k) {
        vector<int> vc(26);
        for (int i = 0;  i < word.size(); ++ i) {
            ++ vc[word[i] - 'a'];
        }
        vector<int> vnz;
        for (int i : vc) {
            if (i) {
                vnz.push_back(i);
            }
        }
        int n = word.size();
        int res = n;
        for (int i = 0; i <= n; ++ i) {
            int t = fn(i, vnz, k);
            if (res > t)
                res = t;
        }
        return res;
    }
};
