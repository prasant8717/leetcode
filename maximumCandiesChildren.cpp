class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 0;
        //int r = ranges::max(candies);
        long long s = 0;
        for (int i = 0; i < candies.size(); ++ i)
            s += candies[i];
        int r = (s / k);
        while (l < r) {
            int m = (l + r + 1) >> 1;
            long long c = 0;
            for (int i = 0; i < candies.size(); ++ i)
                c += candies[i] / m;
            if (c >= k)
                l = m;
            else
                r = m - 1;
        }
        return l;
    }
};
