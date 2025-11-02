class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> visited(m, vector<int>(n, -1));
        // walls = 0 , guards=1 , visited by guards=2
        for (auto& arr : walls) {
            int u = arr[0];
            int v = arr[1];
            visited[u][v] = 0;
        }
        for (auto& arr : guards) {
            int u = arr[0];
            int v = arr[1];
            visited[u][v] = 1;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 1) {
                    for (auto& dir : directions) {
                        int newi = i + dir[0];
                        int newj = j + dir[1];
                        while (newi >= 0 && newj >= 0 && newi < m && newj < n &&
                               visited[newi][newj] != 0 && visited[newi][newj]!=1) {
                            visited[newi][newj] = 2;
                            newi += dir[0];
                            newj += dir[1];
                        }
                    }
                }
            }
        }
        int unguarded = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == -1)
                    unguarded++;
            }
        }
        return unguarded;
    }
};
