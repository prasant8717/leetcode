class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> out(n);
        for (int i = 0; i < n; ++ i)
            out[i] = (i << 1) - n + 1;
        return out;
    }
};
