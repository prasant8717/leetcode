class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0;
        int r = citations.size();
        while (l < r) {
            int t = r - l;
            if (citations[l] < t) {
                ++ l;
            } else {
                -- r;
            }
        }
        return citations.size() - l;
    }
};
