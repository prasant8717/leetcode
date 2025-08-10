class group {
private:
    int n;
    vector<int> grp;

    int merge(int l, int r) const {
        return l > r ? l : r;
    }

    void prep(vector<int>& vn, int i, int l, int r) {
        if (l == r) {
            grp[i] = vn[l];
            return;
        }
        int m = (l + r) >> 1;
        prep(vn, 2 * i + 1, l, m);
        prep(vn, 2 * i + 2, m + 1, r);
        grp[i] = merge(grp[2 * i + 1], grp[2 * i + 2]);
    }

    void final(int idx, int l, int r, int i, int val) {
        if (l == r) {
            grp[idx] = val;
            return;
        }
        int m = (l + r) / 2;
        if (i <= m)
            final(2 * idx + 1, l, m, i, val);
        else
            final(2 * idx + 2, m + 1, r, i, val);
        grp[idx] = merge(grp[2 * idx + 1], grp[2 * idx + 2]);
    }

    int search(int i, int l, int r, int t) {
        if (grp[i] < t)
            return -1;
        if (l == r) {
            final(l, -1);
            return l;
        }
        int m = (l + r) / 2;
        int lc = grp[2 * i + 1];
        return lc >= t ? search(2 * i + 1, l, m, t) :
                        search(2 * i + 2, m + 1, r, t);
    }

public:
    int search(int t) {
        return search(0, 0, n - 1, t);
    }

    explicit group(vector<int>& vn) : n(vn.size()), grp(n << 2) {
        prep(vn, 0, 0, n - 1);
    }

    void final(int i, int v) {
        final(0, 0, n - 1, i, v);
    }
};
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int res = 0;
        group grp(baskets);
        for (int i = 0; i < fruits.size(); ++ i)
            if (grp.search(fruits[i]) == -1)
                ++ res;
        return res;
    }
};
