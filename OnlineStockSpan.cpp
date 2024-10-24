class StockSpanner {
public:
    vector<int> v;
    int idx;
    StockSpanner() {
        idx = 0;
    }
    
    int next(int price) {
        idx ++;
        v.push_back(price);
        int cnt = 0;
        for (int i = 0; i < idx; ++ i) {
            if (v[idx - 1 - i] <= price) {
                ++ cnt;
            } else {
                break;
            }
        }
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
