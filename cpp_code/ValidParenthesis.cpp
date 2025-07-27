class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); ++ i) {
            if (s[i] == '(') {
                stk.push(')');
            }
            else if (s[i] == '[') {
                stk.push(']');
            }
            else if (s[i] == '{') {
                stk.push('}');
            }
            else {
                if ((stk.empty() == true) || (stk.top() != s[i]))
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
