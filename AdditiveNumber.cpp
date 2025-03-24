class Solution {
private:
    bool check(long long l1, long long l2, string num) {
        if (num == "")
            return true;
        if ((l1 + l2 > 0) && (num[0] == '0'))
            return false;
        for (int i = 1; i < min((int)num.size() + 1, 19); ++ i)
            if (l1 + l2 == stoll(num.substr(0, i)))
                if (check(l2, l1 + l2, num.substr(i, num.size() - i)))
                    return true;
        return false;
    }

public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int i = 1; i < min(n - 1, 19); ++ i) {
            for (int j = i + 1; j < min(n, i + 19); ++ j) {
                if ((i > 1) && (num[0] == '0'))
                    break;
                if (((j - i) > 1) && (num[i] == '0'))
                    continue;
                long long l1 = stoll(num.substr(0, i));
                long long l2 = stoll(num.substr(i, j - i));
                if (check(l1, l2, num.substr(j, n - j)))
                    return true;
            }
        }
        return false;
    }
};
