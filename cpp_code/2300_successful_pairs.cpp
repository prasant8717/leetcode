class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res;
        sort(potions.begin(), potions.end());

        for(int i = 0; i < spells.size(); ++i)
        {
            int tmp = potionCount(potions, spells[i], success);
            res.push_back(tmp);
        }
        return res;
    }

    int potionCount(vector<int> &potions, int spell, long long success)
    {
        int begin = 0;
        int end = potions.size() - 1;
        int res = -1;

        while(begin <= end)
        {
            int mid = begin + (end - begin) / 2;
            long long tmp = (long long)spell * potions[mid];
            if(tmp >= success)
            {
                res = mid;
                end = mid - 1;
            }
            else
            {
                begin = mid + 1;
            }
        }

        if (res != -1)
        {
            res = potions.size() - res;
        }
        else
        {
            res = 0;
        }
        return res;        
    }
};
