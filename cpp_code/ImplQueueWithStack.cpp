class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        peek();
        int t = s2.top();
        s2.pop();
        return t;        
    }
    
    int peek() {
        if (s2.empty() != 0)
            while (s1.empty() == 0) {
                s2.push(s1.top());
                s1.pop();
            }
        return s2.top();        
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
