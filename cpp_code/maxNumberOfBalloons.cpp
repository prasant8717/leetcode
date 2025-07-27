class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> vc(26);
        for (int i = 0; i < text.length(); ++ i)
            vc[text[i] - 'a'] ++;
        vc['o' - 'a'] >>= 1;
        vc['l' - 'a'] >>= 1;
        int res = 1500;
        string t = "balon";
        for (int i = 0; i < t.length(); ++ i) {
            int x = vc[t[i] - 'a'];
            if (res > x)
                res = x;
        }
        return res;
    }
};
