class Solution {
public:
    vector<int> beautifulArray(int n) {
        if (n == 1)
            return {1};
        vector<int> vl = beautifulArray((n + 1) >> 1);
        vector<int> vr = beautifulArray(n >> 1);
        vector<int> out(n);
        int i = 0;
        for (int k = 0; k < vl.size(); ++ k ) {
            out[i] = (vl[k] << 1) - 1;
            i ++;
        }
        for (int k = 0; k < vr.size(); ++ k) {
            out[i] = (vr[k] << 1);
            i ++;
        }
        return out;
    }
};
