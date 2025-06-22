class Solution {
public:
    int calculate(string s) {
        int t = 0;
        int n = s.size();
        char sg = '+';
        stack<int> stk;
        for (int i = 0; i < n; ++ i) {
            char c = s[i];
            if (isdigit(c)) t = t * 10 + (c - '0');
            if (i == n - 1 || c == '+' ||
                c == '-' || c == '*' || c == '/') {
                if (sg == '+')
                    stk.push(t);
                else if (sg == '-')
                    stk.push(-t);
                else if (sg == '*') {
                    int tt = stk.top();
                    stk.pop();
                    stk.push(tt * t);
                } else {
                    int tt = stk.top();
                    stk.pop();
                    stk.push(tt / t);
                }
                sg = c;
                t = 0;
            }
        }
        int res = 0;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};
