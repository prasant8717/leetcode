class Solution {
 private:
    multiset<int> ms;
    int mh() {
        return ms.empty() ? 0 : *ms.rbegin();
    }

public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> vo;
        vector<vector<int>> vv;
        for (int i = 0; i < buildings.size(); ++ i) {
            vv.push_back({buildings[i][0], buildings[i][2]});
            vv.push_back({buildings[i][1], -buildings[i][2]});
        }
        ranges::sort(vv, ranges::less{}, [](vector<int>& v) {
            return pair<int, int>{v[0], -v[1]};
        });
        for (vector<int>& ev : vv) {
            int x = ev[0];
            int h = abs(ev[1]);
            int f = ev[1] > 0;
            if (f) {
                if (h > mh())
                    vo.push_back({x, h});
                    ms.insert(h);
            } else {
                ms.erase(ms.equal_range(h).first);
                if (h > mh())
                    vo.push_back({x, mh()});
            }
        }
        return vo;
    }
};
