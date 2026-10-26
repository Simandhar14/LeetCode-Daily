//cpp
class Solution {
public:
    int m, n;
    typedef long long ll;
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
    ll dfs(int i, int j, vector<vector<bool>>& visited,
            vector<vector<int>>& grid) {
        if (grid[i][j] == 0)
            return 0;
        visited[i][j] = true;
        ll islandSum = grid[i][j];
        for (auto& d : dir) {
            int newi = i + d[0];
            int newj = j + d[1];
            if (newi < 0 || newj < 0 || newi >= m || newj >= n ||
                grid[newi][newj] == 0 || visited[newi][newj])
                continue;
            islandSum += dfs(newi, newj, visited, grid);
        }
        return islandSum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        int result = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0 && !visited[i][j]) {
                    ll islandSum = dfs(i, j, visited, grid);
                    if (islandSum % k == 0)
                        result++;
                }
            }
        }
        return result;
    }
};
