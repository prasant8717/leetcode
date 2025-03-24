class MyCircularQueue {
private:
    vector<int> v;
    int m;
    int s;
    int f;

public:
    MyCircularQueue(int k) {
        m = k;
        v = vector<int>(k);
        s = 0;
        f = 0;
    }

    bool enQueue(int value) {
        if (isFull() != 0)
            return false;
        v[(f + s) % m] = value;
        s ++;
        return true;
    }

    bool deQueue() {
        if (isEmpty() != 0)
            return false;
        f = (f + 1) % m;
        s --;
        return true;
    }

    int Front() {
        if (isEmpty() != 0)
            return -1;
        return v[f];
    }

    int Rear() {
        if (isEmpty() != 0)
            return -1;
        return v[(f + s - 1) % m];
    }

    bool isEmpty() {
        return s == 0;
    }

    bool isFull() {
        return s == m;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
