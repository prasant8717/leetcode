class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int res = 0;
        int n = minutesToTest / minutesToDie + 1;
        for (int i = 1; i < buckets; i *= n)
            ++ res;
        return res;
    }
};
