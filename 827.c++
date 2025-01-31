class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i,
            int j,int n) {
        if (i < 0 || j < 0 || i >= n || j >= n || visited[i][j] ||
            grid[i][j] == 0) {
            return 0;
        }
        visited[i][j] = true;
        int up = dfs(grid, visited, i - 1, j,n);
        int down = dfs(grid, visited, i + 1, j,n);
        int left = dfs(grid, visited, i, j - 1,n);
        int right = dfs(grid, visited, i, j + 1,n);
        return grid[i][j] + up + down + left + right;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int largestisland = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                     vector<vector<bool>> visited(n, vector<bool>(n, false));
                    grid[i][j] = 1;
                    largestisland =
                        max(largestisland, dfs(grid, visited, i, j,n));
                    grid[i][j] = 0;
                }
            }
        }
        return largestisland==INT_MIN ? n*n : largestisland;
    }
};