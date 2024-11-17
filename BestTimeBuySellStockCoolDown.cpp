class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int cp = INT_MIN;
        int pp = 0;
        for (int i = 0; i < prices.size(); ++ i) {
            int t = res;
            if (res < cp + prices[i])
                res = cp + prices[i];
            if (cp < pp - prices[i])
                cp = pp - prices[i];
            pp = t;
        }
        return res;        
    }
};
