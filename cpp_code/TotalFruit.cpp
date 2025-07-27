class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> um;
        int res = 0;
        int j = 0;
        for (int i = 0; i < fruits.size(); ++ i) {
            int t = fruits[i];
            ++ um[t];
            while (um.size() > 2) {
                int k = fruits[j ++];
                if (-- um[k] == 0)
                    um.erase(k);
            }
            if (res < i - j + 1)
                res = i - j + 1;
        }
        return res;
    }
};
