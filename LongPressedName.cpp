class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int c = 0;
        int l = name.length();
        for (int i = 0; i < typed.length(); ++ i)
            if ((c < l) && (name[c] == typed[i]))
                ++ c;
            else if ((i == 0) || (typed[i] != typed[i - 1]))
                return false;
        bool res = false;
        if (c == l)
            res = true;
        return res;
    }
};
