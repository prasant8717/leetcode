class Solution {
public:
    int change(int amount, vector<int>& coins) {
        unsigned int v[amount + 1];
        memset(v, 0, sizeof(v));
        v[0] = 1;
        for (int i = 0; i < coins.size(); ++ i) {
            for (int j = coins[i]; j <= amount; ++ j) {
                v[j] += v[j - coins[i]];
            }
        }
        return v[amount];
    }
};
