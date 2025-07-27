class Solution {
public:
    vector<int> vsol;

    Solution(vector<int>& w) {
        int sz = w.size();
        vsol.resize(sz + 1);
        for (int i = 0; i < sz; ++i)
            vsol[i + 1] = vsol[i] + w[i];
    }

    int pickIndex() {
        int sz = vsol.size();
        int tmp = 1 + rand() % vsol[sz - 1];
        int l = 1;
        int r = sz - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (vsol[m] >= tmp)
                r = m;
            else
                l = m + 1;
        }
        return l - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
