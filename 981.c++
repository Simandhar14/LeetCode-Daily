class TimeMap {
public:
    typedef pair<int, string> P;
    unordered_map<string, vector<P>> mp;
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        string ans = "";
        if (mp.count(key)) {
            if (timestamp >= mp[key].back().first) {
                ans = mp[key].back().second;
                return ans;
            } else if (timestamp < mp[key][0].first) {
                return "";
            } else {
                for (int i = 0; i < mp[key].size(); i++) {
                    int time = mp[key][i].first;
                    if (time > timestamp)
                        break;
                    ans = mp[key][i].second;
                }
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */