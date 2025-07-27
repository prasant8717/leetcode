class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> out(temperatures.size());
        stack<int> stk;
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!stk.empty() &&
                    temperatures[stk.top()] < temperatures[i]) {
                const int idx = stk.top();
                stk.pop();
                out[idx] = i - idx;
            }
            stk.push(i);
        }
        return out;    
    }
};
