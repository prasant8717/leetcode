class Solution {
public:
    int side(vector<int>& p1, vector<int>& p2) {
        int x = (p1[0] - p2[0]);
        int xx = x * x;
        int y = (p1[1] - p2[1]);
        int yy = y * y;
        return xx + yy;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int s1 = side(p1, p2);
        int s2 = side(p2, p3);
        int s3 = side(p3, p4);
        int s4 = side(p1, p4);
        int s5 = side(p2, p4);
        int s6 = side(p1, p3);
        unordered_set<int> us({s1, s2, s3, s4, s5, s6});
        if ((us.count(0) == 0) && (us.size() == 2))
            return true;
        return false;
    }
};
