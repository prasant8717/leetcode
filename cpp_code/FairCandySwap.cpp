class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sa = 0;
        int na = aliceSizes.size();
        for (int i = 0; i < na; ++ i)
            sa += aliceSizes[i];
        int sb = 0;
        int nb = bobSizes.size();
        for (int i = 0; i < nb; ++ i)
            sb += bobSizes[i];
        int d = (sa - sb) >> 1;
        unordered_set<int> us(bobSizes.begin(), bobSizes.end());
        vector<int> res;
        for (int i = 0; i < na; ++ i) {
            int t = aliceSizes[i] - d;
            if (us.count(t) != 0) {
                res = vector<int>{aliceSizes[i], t};
                break;
            }
        }
        return res;
    }
};
