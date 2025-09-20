class Router {
public:
    queue<string> que;
    unordered_map<string, vector<int>> storage;
    unordered_map<int, vector<int>> destMap;
    int limit;

    Router(int memoryLimit) { limit = memoryLimit; }

    bool addPacket(int source, int destination, int timestamp) {
        string ss = to_string(source) + "_" + to_string(destination) + "_" +
                    to_string(timestamp);
        if (storage.find(ss) != storage.end())
            return false;
        if (storage.size() >= limit) {
            forwardPacket();
        }
        vector<int> temp = {source, destination, timestamp};

        storage[ss] = temp;
        que.push(ss);
        destMap[destination].push_back(timestamp);

        return true;
    }

    vector<int> forwardPacket() {
        if (que.empty())
            return {};
        auto temp = que.front();
        que.pop();
        vector<int> ans = storage[temp];
        storage.erase(temp);
        destMap[ans[1]].erase(begin(destMap[ans[1]]));
        if (destMap[ans[1]].size() == 0)
            destMap.erase(ans[1]);
        return ans;
    }

    int getCount(int destination, int startTime, int endTime) {
        int count = 0;
        auto& mp = destMap[destination];
        auto it_start = lower_bound(begin(mp), end(mp), startTime);
        auto it_end = upper_bound(begin(mp), end(mp), endTime);
        return it_end - it_start;
    }
};
