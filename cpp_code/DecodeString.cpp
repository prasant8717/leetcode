class Solution {
public:
    string decodeString(string s) {
        string res = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ']') {
                res.push_back(s[i]);
            }
            else {
                string tmp = "";
                while (!res.empty() && res.back() != '[') {
                    tmp.push_back(res.back());
                    res.pop_back();
                }
                reverse(tmp.begin(), tmp.end());
                res.pop_back();
                string num = "";
                while (!res.empty() && res.back() >= '0'
                   && res.back() <= '9') {
                    num.push_back(res.back());
                    res.pop_back();
                }
                reverse(num.begin(), num.end());
                if (num.size() != 0) {
                    int itr = stoi(num);
                    while (itr--) {
                        res += tmp;
                    }
                }
            }
        }
        return res;        
    }
};
