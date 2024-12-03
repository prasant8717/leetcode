class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0)
            return "0";
        string out;
        string r;
        int sg = 0;
        if (num < 0) {
            sg = -1;
            num = num * sg;
        }
        while (num) {
            r += to_string(num % 7);
            num = (num / 7);
        }
        if (sg == -1)
            out += '-';
        for (int i = r.size() - 1; i >= 0; -- i)
            out += r[i];
        return out;
    }
};
