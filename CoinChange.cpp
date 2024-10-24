class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> out(amount + 1, amount + 1);
        out[0] = 0;
        for (int i = 0; i < coins.size(); ++ i)
            for (int ii = coins[i]; ii <= amount; ++ ii)
                out[ii] = min(out[ii], out[ii - coins[i]] + 1);
        return out[amount] == amount + 1 ? -1 : out[amount];
    }
};
