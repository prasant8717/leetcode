class Solution {
public:
    unordered_set<int> us;
    int r;
    int c;
    Solution(int m, int n) {
        r = m;
        c = n;
    }
    
    vector<int> flip() {
        int t = (r * c);
        if (us.size() == t)
            return {};
        int i = rand() % t;
        while (us.contains(i))
            i = ++ i % t;
        us.insert(i);
        return {i / c, i % c};
    }
    
    void reset() {
        us = {};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
