class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int c = count(blocks.begin(), blocks.begin() + k, 'W');
        int res = c;
        for (int i = k; i < blocks.size(); ++ i) {
            if (blocks[i] == 'W')
                ++ c;
            if (blocks[i - k] == 'W')
                -- c;
            if (res > c)
                res = c;
        }
        return res;
    }
};
