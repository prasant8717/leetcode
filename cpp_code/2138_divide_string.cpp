class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> vs;
        int n = s.size();
        int p = 0;
        int m = (int) (n / k);
        int r = (n % k);
        while (m) {
            vs.push_back(s.substr(p, k));
            p += k;
            -- m;
        }
        if (r) {
            vs.push_back(s.substr(p));
            r = k - r;
        }
        while (r) {
            vs[(int)(n / k)] += fill;
            -- r;
        }
        return vs;
    }
};
