class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    bool cross(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j) {
        if (i == grid.size() - 1)
            return true;

        visited[i][j] = 1;

        for (auto& dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            if (ni >= 0 && nj >= 0 && ni < grid.size() && nj < grid[0].size() &&
                grid[ni][nj] == 0 && !visited[ni][nj]) {
                if (cross(grid, visited, ni, nj))
                    return true;
            }
        }
        return false;
    }

    bool canCross(int day, int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int>(col, 0));


        for (int d = 0; d <= day; d++) {
            int i = cells[d][0] - 1;
            int j = cells[d][1] - 1;
            grid[i][j] = 1;
        }

        for (int j = 0; j < col; j++) {
            if (grid[0][j] == 1) continue;
            vector<vector<int>> visited(row, vector<int>(col, 0));
            if (cross(grid, visited, 0, j))
                return true;
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low = 0, high = cells.size() - 1;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canCross(mid, row, col, cells)) {
                ans = mid + 1;   
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
