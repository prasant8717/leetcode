class Solution {
public:
    int findLUSlength(string a, string b) {
        int res = -1;
        if (a != b) {
            res = a.size();
            if (res < b.size())
                res = b.size();
        }
        return res;
    }
};
