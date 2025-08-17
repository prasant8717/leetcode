class Solution {
public:
    string largestGoodInteger(string num) {
        int l = num.length();
        int m = -1;
        string out = "";
        for (int i = 0; i < l - 2; ++ i) {
            if ((num[i] == num[i + 1]) && (num[i + 2] == num[i])) {
                int t = num[i] * 100 + num[i] * 10 + num[i];
                if (t > m) {
                    m = t;
                    out = num[i];
                    out += num[i];
                    out += num[i];
                }
            }
        }
        return out;
    }
};
