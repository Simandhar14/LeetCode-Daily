class Solution {
public:
    int dfs(int i, int j, vector<vector<bool>>& visited,
            vector<vector<int>>& grid, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] ||
            grid[i][j] == 0) {
            return 0;
        }
        visited[i][j] = true;
        int left =  dfs(i, j - 1, visited, grid, m, n);
        int right =  dfs(i, j + 1, visited, grid, m, n);
        int up = dfs(i - 1, j, visited, grid, m, n);
        int down =  dfs(i + 1, j, visited, grid, m, n);
        return grid[i][j]+left+right+down+up;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int maxfish = INT_MIN;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    int fishes = dfs(i, j, visited, grid, m, n);
                    maxfish = max(maxfish, fishes);
                }
            }
        }
        return maxfish==INT_MIN ? 0 : maxfish;
    }
};