class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> pq;

    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; ++i)
            pq.push(i);
    }
    
    int popSmallest() {
        int num = pq.top();
        pq.pop();
        return num;
    }
    
    void addBack(int num) {
        priority_queue<int, vector<int>, greater<int>> dq = pq;
        while(dq.size() != 0) {
            if (dq.top() == num)
                return;
            dq.pop();
        }
        pq.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
