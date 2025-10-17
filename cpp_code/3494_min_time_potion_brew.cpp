class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        long long s = accumulate(skill.begin(), skill.end(), 0L);
        long long res = s * mana[0];
        for (int i = 1; i < mana.size(); ++ i) {
            long long t = res;
            for (int j = skill.size() - 2; j >= 0; -- j) {
                t -= static_cast<long long>(skill[j + 1]) * mana[i - 1];
                res = max(t, res - static_cast<long>(skill[j]) * mana[i]);
            }
            res += s * mana[i];
        }
        return res;
    }
};
