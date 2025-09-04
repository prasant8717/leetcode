class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        vector<int> vm = *ranges::max_element(dimensions,
                        [](vector<int>& v1, vector<int>& v2) {
            int t1 = v1[0] * v1[0] + v1[1] * v1[1];
            int t2 = v2[0] * v2[0] + v2[1] * v2[1];
            int a1 = v1[0] * v1[1];
            int a2 = v2[0] * v2[1];
            return (t1 == t2) ? (a1 < a2) : (t1 < t2);
        });
        return vm[0] * vm[1];
    }
};
