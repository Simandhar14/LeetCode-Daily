//brute force
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        k = k % (m * n);
        vector<int> start;
        vector<vector<int>> result = grid;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (k == 0)
                    break;
                start.push_back(grid[i][j]);
                k--;
            }
        }
        int row = 0, col = 0;
        while (!start.empty()) {
            result[row][col] = start.back();
            start.pop_back();
            col++;
            if (col == n) {
                col = 0;
                row++;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row == m)
                    break;
                cout << row << " " << col << endl;
                result[row][col] = grid[i][j];
                col++;
                if (col == n) {
                    col = 0;
                    row++;
                }
                if (row == m)
                    break;
            }
        }
        return result;
    }
};

//better approach
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        k = k % (m * n);
        while (k--) {
            int prev = INT_MIN;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (prev == INT_MIN) {
                        prev = grid[i][j];
                        continue;
                    }
                    int temp = grid[i][j];
                    grid[i][j] = prev;
                    prev = temp;
                }
            }
            grid[0][0] = prev;
        }
        return grid;
    }
};
