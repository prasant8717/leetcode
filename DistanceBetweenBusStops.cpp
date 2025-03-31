class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int d1 = 0;
        int n = distance.size();
        for (int i = 0; i < n; ++ i)
            d1 += distance[i];
        int d2 = 0;
        while (start != destination) {
            d2 += distance[start];
            start = (start + 1) % n;
        }
        return ((d1 - d2) < d2) ? d1 - d2 : d2;
    }
};
