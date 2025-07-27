class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto compare = [&nums1, &nums2](pair<int, int>& p1, pair<int, int>& p2) {
            return nums1[p1.first] + nums2[p1.second] > nums1[p2.first] + nums2[p2.second];
        };
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> vout;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);
        for (int i = 0; i < min(k, n1); i++)
            pq.emplace(i, 0);
        while (k-- && (pq.empty() == 0)) {
            auto [p, q] = pq.top();
            pq.pop();
            vout.emplace_back(initializer_list<int>{nums1[p], nums2[q]});
            if (q + 1 < n2)
                pq.emplace(p, q + 1);
        }
        return vout;
    }
};
