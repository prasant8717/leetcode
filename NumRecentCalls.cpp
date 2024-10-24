class RecentCounter {
public:
    int *que;
    int start;
    RecentCounter() {
        que = new int [10000];
        //for (int i = 0; i < 10000; ++i) {
        //    que[i] = 0;
        //}
        start = -1;
    }
    
    int ping(int t) {
        start ++;
        que[start] = t;
        int rng1 = t;
        int rng2 = 0;
        if (t > 3000) {
            rng2 = t - 3000;
        }
        int ret = 0;
        for (int i = 0; i <= start; ++i) {
            if ((que[i] <= rng1) && (que[i] >= rng2)) {
                ret ++;
            }
        }
        return ret;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
