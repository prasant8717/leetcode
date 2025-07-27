class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> map;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto& v = map[key];
        pair<int, string> p = {timestamp, string({127})};
        auto i = upper_bound(v.begin(), v.end(), p);
        return i == v.begin() ? "" : (i - 1)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
