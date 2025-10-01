class FoodRatings {
private:
    unordered_map<string, int> umsi;
    unordered_map<string, string> umss;
    unordered_map<string, set<pair<int, string>>> umsss;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines,
                vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++ i) {
            umsss[cuisines[i]].insert({-ratings[i], foods[i]});
            umss[foods[i]] = cuisines[i];
            umsi[foods[i]] = ratings[i];
        }
    }

    void changeRating(string food, int newRating) {
        string s = umss[food];
        int r = umsi[food];
        auto& rf = umsss[s];
        rf.erase({-r, food});
        rf.insert({-newRating, food});
        umsi[food] = newRating;
    }

    string highestRated(string cuisine) {
        return umsss[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
