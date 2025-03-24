class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(1);
        int k = 0;
        while (n --) {
            k = pq.top();
            pq.pop();
            for (int i = 0; i < primes.size(); ++ i) {
                int t = primes[i];
                if (k <= (INT_MAX / t))
                    pq.push(k * t);
                if ((k % t) == 0)
                    break;
            }
        }
        return k;
    }
};
