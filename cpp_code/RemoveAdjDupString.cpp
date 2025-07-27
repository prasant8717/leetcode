class Solution {
public:
    string removeDuplicates(string s) {
        string os;
        os += s[0];
        for (int i = 1; i < s.size(); ++ i) {
            int l = os.size();
            if (l != 0)
                if (os[l - 1] != s[i])
                    os += s[i];
                else
                    os.erase(l - 1);
            else
                os += s[i];
        }
        return os;
    }
};
