class Solution {
private:
    unordered_map<string, vector<int>> um;

    vector<int> compute(string exp) {
        if (um.count(exp))
            return um[exp];
        if (exp.size() < 3)
            return {stoi(exp)};
        vector<int> out;
        int n = exp.size();
        for (int i = 0; i < n; ++ i) {
            char c = exp[i];
            if (c == '-' || c == '+' || c == '*') {
                vector<int> vl = compute(exp.substr(0, i));
                vector<int> vr = compute(exp.substr(i + 1, n - i - 1));
                for (int& l : vl) {
                    for (int& r : vr) {
                        if (c == '-')
                            out.push_back(l - r);
                        else if (c == '+')
                            out.push_back(l + r);
                        else
                            out.push_back(l * r);
                    }
                }
            }
        }
        um[exp] = out;
        return out;
    }

public:
    vector<int> diffWaysToCompute(string expression) {
        return compute(expression);
    }
};
