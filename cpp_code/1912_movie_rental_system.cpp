class MovieRentingSystem {
private:
    struct hash_pair {
        size_t operator()(const pair<int, int>& p) const {
            return p.first ^ p.second;
        }
    };
    unordered_map<pair<int, int>, int, hash_pair> umhp;
    set<pair<int, pair<int, int>>> sp;
    unordered_map<int, set<pair<int, int>>> ums;

public:
    MovieRentingSystem(int n, vector<vector<int>>& vvi) {
        for (int i = 0;  i < vvi.size(); ++ i) {
            int s = vvi[i][0];
            int m = vvi[i][1];
            int p = vvi[i][2];
            ums[m].insert({p, s});
            umhp[{s, m}] = p;
        }
    }

    vector<int> search(int movie) {
        int i = 0;
        vector<int> out;
        for (auto& [p, s] : ums[movie]) {
            out.push_back(s);
            if (++ i >= 5)
                break;
        }
        return out;
    }

    void rent(int shop, int movie) {
        int p = umhp[{shop, movie}];
        ums[movie].erase({p, shop});
        sp.insert({p, {shop, movie}});
    }

    void drop(int shop, int movie) {
        int p = umhp[{shop, movie}];
        ums[movie].insert({p, shop});
        sp.erase({p, {shop, movie}});
    }

    vector<vector<int>> report() {
        vector<vector<int>> out;
        int i = 0;
        for (auto& [_, sm] : sp) {
            out.push_back({sm.first, sm.second});
            if (++ i >= 5)
                break;
        }
        return out;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
