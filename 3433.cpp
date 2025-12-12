class Solution {
public:
    vector<int> countMentions(int numberOfUsers,
                              vector<vector<string>>& events) {
        sort(begin(events), end(events),
             [&](vector<string>& a, vector<string>& b) {
                 int timestamp1 = stoi(a[1]);
                 int timestamp2 = stoi(b[1]);
                  if(timestamp1==timestamp2) return a[0]>b[0];
                 return timestamp1 < timestamp2;
             });
        vector<int> countMention(numberOfUsers, 0);
        unordered_map<int, int> online;
        for (int i = 0; i < numberOfUsers; i++)
            online[i] = INT_MIN;
        int len = events.size();
        for (int i = 0; i < len; i++) {
            string event = events[i][0];
            int timestamp = stoi(events[i][1]);
            string mentions = events[i][2];
            cout << event << " " << timestamp << " " << mentions << endl;
            if (event == "MESSAGE") {
                if (mentions == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++)
                        countMention[i]++;

                } else if (mentions == "HERE") {
                    for (auto it = online.begin(); it != online.end(); it++) {
                        int id = it->first;
                        int idTimestamp = it->second;
                        if (timestamp >= idTimestamp) {
                            countMention[id]++;
                        }
                    }
                } else {
                    stringstream ss(mentions);
                    string word;
                    while (ss >> word) {
                        int id = stoi(word.substr(2));
                        countMention[id]++;
                    }
                }
            } else {
                int newTimestamp = timestamp + 60;
                int id = stoi(mentions);
                online[id] = newTimestamp;
            }
        }
        return countMention;
    }
};
