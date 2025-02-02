class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int level = 0;
        int m = grid.size();
        int n = grid[0].size();
        int freshorange=0;
        queue<pair<int, int>> que;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    que.push({i, j});
                }
                if (grid[i][j] == 1)
                    freshorange++;
            }
        }
        if(freshorange==0) return 0;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                auto temp = que.front();
                que.pop();
                for (auto dir : directions) {
                    int newi = temp.first + dir[0];
                    int newj = temp.second + dir[1];
                    if (newi >= 0 && newj >= 0 && newi < m && newj < n &&
                        grid[newi][newj] == 1) {
                        grid[newi][newj] = 0;
                        que.push({newi, newj});
                        freshorange--;
                    }
                }
            }
            level++;
        }
        return freshorange == 0 ? level-1 : -1;
    }
};