class Solution {
public:
    string removeKdigits(string num, int k) {
        string s;
        for (int i = 0; i < num.size(); ++ i) {
            while ((k > 0) && (s.size() > 0) && (s.back() > num[i])) {
                s.pop_back();
                -- k;
            }
            s += num[i];
        }
        while (k --) {
            s.pop_back();
        }
        int i = 0;
        for (; (i < s.size()) && (s[i] == '0'); ++ i) {
        }
        string res = s.substr(i);
        if (res == "")
            res = "0";
        return res;        
    }
};
