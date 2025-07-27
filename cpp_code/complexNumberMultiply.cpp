class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int r1;
        int i1;
        int r2;
        int i2;
        sscanf(num1.c_str(), "%d+%di", &r1, &i1);
        sscanf(num2.c_str(), "%d+%di", &r2, &i2);
        string s = to_string(r1 * r2 - i1 * i2);
        s += "+";
        s += to_string(r1 * i2 + r2 * i1) + "i";
        return s;
    }
};
