class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> out;
        int min = INT_MAX;
        unordered_map<string, int> umap;
        for (int i = 0; i < list2.size(); ++ i)
            umap[list2[i]] = i;
        for (int i = 0; i < list1.size(); ++ i) {
            if (umap.count(list1[i]) != 0) {
                int t = i + umap[list1[i]];
                if (min > t) {
                    out.clear();
                    out.push_back(list1[i]);
                    min = t;
                } else if (min == t) {
                    out.push_back(list1[i]);
                }
            }
        }
        return out;
    }
};
