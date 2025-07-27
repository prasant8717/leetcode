class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int l = arr.size();
        for (int i = 0; i < l; ++ i) {
            for (int j = l - 1; j >= 0; -- j) {
                if ((i != j) && (arr[i] == (2 * arr[j])))
                    return true;
            }
        }
        return false;
    }
};
