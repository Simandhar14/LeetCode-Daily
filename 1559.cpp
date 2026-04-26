//cpp
class Solution {
public:
    int m, n;
    vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool dfs(int i, int j, vector<vector<char>>& grid,
             vector<vector<bool>>& visited, int parenti, int parentj) {
        visited[i][j] = true;
        for (auto& d : dir) {
            int newi = i + d[0];
            int newj = j + d[1];
            if (newi < m && newj < n && newi >= 0 && newj >= 0) {
                if (grid[newi][newj] != grid[i][j])
                    continue;
                if (!visited[newi][newj]) {
                    if (dfs(newi, newj, grid, visited, i, j))
                        return true;
                } else {
                    if (newi != parenti || newj != parentj)
                        return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && dfs(i, j, grid, visited, -1, -1)) {
                    return true;
                }
            }
        }
        return false;
    }
};
