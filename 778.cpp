//Dijkstra's Algorithm
class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> result(n, vector<int>(n, INT_MAX));
        priority_queue<p, vector<p>, greater<p>> pq;
        result[0][0] = 0;
        pq.push({grid[0][0], {0, 0}});
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int time = top.first;
            int i = top.second.first;
            int j = top.second.second;
            for (auto& dir : directions) {
                int newi = i + dir[0];
                int newj = j + dir[1];
                if (newi >= 0 && newj >= 0 && newi < grid.size() &&
                    newj < grid.size()) {
                    int newtime = max(grid[newi][newj], time);
                    if (newtime < result[newi][newj]) {
                        result[newi][newj] = newtime;
                        pq.push({newtime, {newi, newj}});
                    }
                }
            }
        }
        return result[n - 1][n - 1];
    }
};
