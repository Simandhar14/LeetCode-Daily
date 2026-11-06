//cpp
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {
        int len = logs.size();
        int m = queries.size();

        vector<pair<int, int>> q;
        for (int i = 0; i < m; i++)
            q.push_back({queries[i], i});
        sort(q.begin(), q.end());

        sort(logs.begin(), logs.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });

        unordered_map<int, int> freq;
        vector<int> result(m);
        int i = 0, j = 0;

        for (int idx = 0; idx < m; idx++) {
            int t = q[idx].first;

            while (j < len && logs[j][1] <= t) {
                freq[logs[j][0]]++;
                j++;
            }
            while (i < j && logs[i][1] < t - x) {
                if (--freq[logs[i][0]] == 0)
                    freq.erase(logs[i][0]);
                i++;
            }
            result[q[idx].second] = n - freq.size();
        }
        return result;
    }
};
