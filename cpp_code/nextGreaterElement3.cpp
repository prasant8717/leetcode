class Solution {
public:
    int nextGreaterElement(int n) {
        string ts = to_string(n);
        int k = ts.size();
        int i = k - 2;
        int j = k - 1;
        for (; (i >= 0) && (ts[i] >= ts[i + 1]); -- i)
            ;
        if (i < 0)
            return -1;
        for (; ts[i] >= ts[j]; -- j)
            ;
        char c = ts[i];
        ts[i] = ts[j];
        ts[j] = c;
        reverse(ts.begin() + i + 1, ts.end());
        long res = stol(ts);
        if (res > INT_MAX)
            res = -1;
        return res;
    }
};
