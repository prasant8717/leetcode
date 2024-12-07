class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> us(candyType.begin(), candyType.end());
        int res = candyType.size() >> 1;
        if (res > us.size())
            res = us.size();
        return res;
    }
};
