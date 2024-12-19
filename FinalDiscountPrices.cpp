class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> out;
        int n = prices.size();
        for (int i = 0; i < n; ++ i) {
            int t = prices[i];
            for (int j = i + 1; j < n; ++ j) {
                if (prices[i] >= prices[j]) {
                    t -= prices[j];
                    break;
                }
            }
            out.push_back(t);
        }
        return out;
    }
};
