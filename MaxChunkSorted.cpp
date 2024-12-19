class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int m = INT_MIN;
        int res = 0;
        for (int i = 0; i < arr.size(); ++ i) {
            if (m < arr[i])
                m = arr[i];
            if (m == i)
                ++ res;
        }
        return res;        
    }
};
