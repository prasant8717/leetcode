class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }
        string res;
        bool neg = (numerator > 0) ^ (denominator > 0);
        if (neg) {
            res += "-";
        }
        long long l1 = abs(1LL * numerator);
        long long l2 = abs(1LL * denominator);
        res += to_string(l1 / l2);
        l1 %= l2;
        if (l1 == 0) {
            return res;
        }
        res += ".";
        unordered_map<long long, int> um;
        while (l1) {
            um[l1] = res.size();
            l1 *= 10;
            res += to_string(l1 / l2);
            l1 %= l2;
            if (um.contains(l1)) {
                res.insert(um[l1], "(");
                res += ")";
                break;
            }
        }
        return res;
    }
};
