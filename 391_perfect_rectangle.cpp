class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int a1 = INT_MAX;
        int b1 = a1;
        int a2 = INT_MIN;
        int b2 = a2;
        long long ar = 0;
        unordered_set<string> us;
        for (int i = 0; i < rectangles.size(); ++ i) {
            ar += (long long) (rectangles[i][2] - rectangles[i][0]) * 
                  (rectangles[i][3] - rectangles[i][1]);
            if (a1 > rectangles[i][0])
                a1 = rectangles[i][0];
            if (b1 > rectangles[i][1])
                b1 = rectangles[i][1];
            if (a2 < rectangles[i][2])
                a2 = rectangles[i][2];
            if (b2 < rectangles[i][3])
                b2 = rectangles[i][3];
            vector<string> vs{to_string(rectangles[i][0]) + " " +
                              to_string(rectangles[i][1]),
                              to_string(rectangles[i][0]) + " " +
                              to_string(rectangles[i][3]),
                              to_string(rectangles[i][2]) + " " +
                              to_string(rectangles[i][1]),
                              to_string(rectangles[i][2]) + " " +
                              to_string(rectangles[i][3])};
            for (string s : vs)
                if (us.insert(s).second == false)
                    us.erase(s);
        }
        if (us.size() != 4)
            return false;
        if ((us.contains(to_string(a1) + " " + to_string(b1)) == 0) ||
            (us.contains(to_string(a1) + " " + to_string(b2)) == 0) ||
            (us.contains(to_string(a2) + " " + to_string(b1)) == 0) ||
            (us.contains(to_string(a2) + " " + to_string(b2)) == 0))
            return false;
        return ar == (long long)(a2 - a1) * (b2 - b1);
    }
};
