class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;
        for (int i = 0; i < moves.size(); ++ i) {
            if (moves[i] == 'L')
                -- y;
            else if (moves[i] == 'R')
                ++ y;
            else if (moves[i] == 'U')
                ++ x;
            else
                -- x;
        }
        return ((x == 0) && (y == 0));
    }
};
