//cpp
class Solution {
public:
    typedef pair<int, int> p;
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> busiest(k, 0);
        set<int> free;
        for (int i = 0; i < k; i++) {
            free.insert(i);
        }
        priority_queue<p, vector<p>, greater<p>> busy;
        for (int i = 0; i < arrival.size(); i++) {
            while (!busy.empty() && arrival[i] >= busy.top().first) {
                free.insert(busy.top().second);
                busy.pop();
            }
            if (free.size() == 0)
                continue;
            int idx = i % k;
            auto it = free.find(idx);
            if (it != free.end()) {
                busy.push({arrival[i] + load[i], *it});
                busiest[*it]++;
                free.erase(it);
            } else {
                it = free.lower_bound(idx);
                if (it != free.end()) {
                    busy.push({arrival[i] + load[i], *it});
                    busiest[*it]++;
                    free.erase(it);
                } else {
                    it = free.begin();
                    busy.push({arrival[i] + load[i], *it});
                    busiest[*it]++;
                    free.erase(it);
                }
            }
        }
        vector<int> result;
        int count = *max_element(begin(busiest), end(busiest));
        for (int i = 0; i < k; i++)
            if (busiest[i] == count)
                result.push_back(i);
        return result;
    }
};
