class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        int j = 0;
        while (j < n) {
            if (arr[i] == 0)
                j ++;
            i ++;
            j ++;
        }
        i --;
        j --;
        while (i >= 0) {
            if (arr[i] == 0) {
                if (j < n)
                    arr[j] = arr[i];
                j --;
            }
            arr[j] = arr[i];
            i --;
            j --;
        }
    }
};
