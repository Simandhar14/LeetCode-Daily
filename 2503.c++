class Solution {
public:
    typedef tuple<int, int, int> tup;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int len = queries.size();
        vector<int> result(len);
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> sortedqueries;
        for (int i = 0; i < len; i++) {
            sortedqueries.push_back({queries[i], i});
        }
        sort(begin(sortedqueries), end(sortedqueries));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<tup, vector<tup>, greater<tup>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        int idx = 0;
        int points = 0;
        while (idx < len && !pq.empty()) {
            auto [val, i, j] = pq.top();
            if (sortedqueries[idx].first > val) {
                pq.pop();
                points++;

            } else {
                result[sortedqueries[idx].second] = points;
                idx++;
                continue;
            }
            for (auto dir : directions) {
                int ni = dir[0] + i;
                int nj = dir[1] + j;
                if (ni >= 0 && nj >= 0 && ni < m && nj < n &&
                    !visited[ni][nj]) {
                    pq.push({grid[ni][nj], ni, nj});
                    visited[ni][nj] = true;
                }
            }
        }
        while (idx < len) {
            result[sortedqueries[idx].second] = points;
            idx++;
        }
        return result;
    }
};
