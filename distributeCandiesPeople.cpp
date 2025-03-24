class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> out(num_people);
        int j = 0;
        int r = 0;
        while (candies != 0)
        {
            for (int i = 0; i < num_people; ++ i) {
                if (candies < 1 + r + i)
                    j = candies;
                else
                    j = 1 + r + i;
                out[i] += j;
                candies -= j;
                if (i == num_people - 1)
                    r = j;
            }
        }
        return out;
    }
};
