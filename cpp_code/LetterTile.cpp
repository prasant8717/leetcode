class Solution {
public:
    int comb(vector<int>& ch) {
        int res = 0;
        for (int i = 0; i < ch.size(); ++ i) {
            if (ch[i] > 0) {
                ++ res;
                -- ch[i];
                res += comb(ch);
                ++ ch[i];
            }
        }
        return res;
    }
    int numTilePossibilities(string tiles) {
        vector<int> ch(26, 0);
        for (int i = 0; i < tiles.size(); ++ i) {
            ++ ch[tiles[i] - 'A'];
        }
        return comb(ch);
    }
};
