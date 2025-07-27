class ProductOfNumbers {
public:
    vector<int> v;
    ProductOfNumbers() {
        v.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            v.clear();
            v.push_back(1);
            return;
        }
        v.push_back(v.back() * num);
    }
    
    int getProduct(int k) {
        int t = v.size();
        return t <= k ? 0 : v.back() / v[t - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
