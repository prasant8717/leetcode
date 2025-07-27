class Solution {
public:
    string multiply(string num1, string num2) {
        if ((num1 == "0") || (num2 == "0"))
            return "0";
        string out(num1.length() + num2.length(), '0');
        for (int i = num1.length() - 1; i >= 0; -- i) {
            for (int j = num2.length() - 1; j >= 0; -- j) {
                int mult = (num1[i] - '0') * (num2[j] - '0');
                int sum = mult + (out[i + j + 1] - '0');
                out[i + j] += sum / 10;
                out[i + j + 1] = '0' + sum % 10;
            }
        }
        int i = out.find_first_not_of('0');
        return i < 0 ? "0" : out.substr(i);
    }
};
