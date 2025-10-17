class Solution {
private:
    vector<int> v;

public:
    Solution(vector<int>& nums) {
        v = std::move(nums);
    }
    
    vector<int> reset() {
        return v;
    }
    
    vector<int> shuffle() {
        vector<int> tv = v;
        for (int i = tv.size() - 1; i > 0; -- i) {
            int j = rand() % (i + 1);
            swap(tv[i], tv[j]);
        }
        return tv;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
