class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int res = 0, sg = 1;
        for (int i = 0; i < s.size(); ++ i) {
            if (isdigit(s[i])) {
                int op = 0;
                int j = i;
                while ((j < s.size()) && isdigit(s[j])) {
                    op = op * 10 + (s[j] - '0');
                    ++ j;
                }
                res += sg * op;
                i = j - 1;
            } else if (s[i] == '+') {
                sg = 1;
            } else if (s[i] == '-') {
                sg = -1;
            } else if (s[i] == '(') {
                st.push(res);
                st.push(sg);
                res = 0;
                sg = 1;
            } else if (s[i] == ')') {
                res *= st.top();
                st.pop();
                res += st.top();
                st.pop();
            }
        }
        return res;        
    }
};
