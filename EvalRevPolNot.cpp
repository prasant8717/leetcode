class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (int i = 0; i < tokens.size(); ++ i) {
            if (tokens[i].size() > 1 || isdigit(tokens[i][0])) {
                stk.push(stoi(tokens[i]));
            } else {
                int op1 = stk.top();
                stk.pop();
                int op2 = stk.top();
                stk.pop();
                if (tokens[i][0] == '+')
                    stk.push(op1 + op2);
                else if (tokens[i][0] == '-')
                    stk.push(op2 - op1);
                else if (tokens[i][0] == '*')
                    stk.push(op1 * op2);
                else
                    stk.push(op2 / op1);
            }
        }
        return stk.top();        
    }
};
