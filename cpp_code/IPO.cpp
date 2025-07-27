struct trade {
    int profit;
    int capital;
};
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        auto compare_capital = [](trade& t1, trade& t2) {
            return t1.capital > t2.capital;
        };
        auto compare_profit = [](trade& t1, trade& t2) {
            return t1.profit < t2.profit;
        };
        priority_queue<trade, vector<trade>, decltype(compare_capital)> pq1(compare_capital);
        priority_queue<trade, vector<trade>, decltype(compare_profit)> pq2(compare_profit);
        for (int i = 0; i < capital.size(); ++ i)
            pq1.emplace(profits[i], capital[i]);
        while (k-- > 0) {
            while (!pq1.empty() && pq1.top().capital <= w)
                pq2.push(pq1.top()), pq1.pop();
            if (pq2.empty())
                break;
            w += pq2.top().profit, pq2.pop();
        }
        return w;        
    }
};
