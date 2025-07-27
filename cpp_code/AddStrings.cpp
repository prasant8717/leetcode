class Solution {
public:
    string addStrings(string num1, string num2) {
        int l1 = num1.size();
        int l2 = num2.size();
        int l = l2 > l1 ? l2 + 1 : l1 + 1;
        vector<int> out(l);
        int i = 0;
        int idx = 0;
        int c = 0;
        for (; (i < l1) && (i < l2); ++ i) {
            int t1 = num1[l1 - 1 - i] - '0';
            int t2 = num2[l2 - 1 - i] - '0';
            int t = t1 + t2 + c;
            out[l - 1 - idx] += t % 10;
            if (t >= 10)
                c = 1;
            else
                c = 0;
            ++ idx;
        }
        for (; i < l1; ++ i) {
            int t = (c + num1[l1 - 1 - i] - '0');
            out[l - 1 - idx] = (t % 10);
            if (t >= 10)
                c = 1;
            else
                c = 0;
            ++ idx;
        }
        for (; i < l2; ++ i) {
            int t = (c + num2[l2 - 1 - i] - '0');
            out[l - 1 - idx] = (t % 10);
            if (t >= 10)
                c = 1;
            else 
                c = 0;
            ++ idx;
        }
        out[l - 1 - idx] = c;
        string str;
        if (out[0] != 0)
            str += to_string(out[0]);
        for (int j = 1; j < out.size(); ++ j)
            str += to_string(out[j]);
        return str;
    }
};
