class Solution {
public:
    int calculate(int startrow, int endrow, int startcol, int endcol,
                  vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int minrow = m;
        int maxrow = -1;
        int mincol = n;
        int maxcol = -1;

        for (int i = startrow; i <= endrow; i++) {
            for (int j = startcol; j <= endcol; j++) {
                if (grid[i][j] == 0)
                    continue;
                maxrow = max(maxrow, i);
                minrow = min(minrow, i);
                mincol = min(mincol, j);
                maxcol = max(maxcol, j);
            }
        }
        if (maxrow == -1) return 0; 
        return (maxrow - minrow + 1) * (maxcol - mincol + 1);
    }

    int cases(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int top, bottom, left, right, middle;
        int ans = INT_MAX;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                top = calculate(0, i - 1, 0, n - 1, grid);
                left = calculate(i, m - 1, 0, j - 1, grid);
                right = calculate(i, m - 1, j, n - 1, grid);
                ans = min({ans, top+ left+ right});

                left = calculate(0, i - 1, 0, j - 1, grid);
                right = calculate(0, i - 1, j, n - 1, grid);
                bottom = calculate(i, m - 1, 0, n - 1, grid);
                ans = min({ans, bottom+ left+right});
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                top = calculate(0, i - 1, 0, n - 1, grid);
                middle = calculate(i, j-1, 0, n - 1, grid);
                bottom = calculate(j, m - 1, 0, n - 1, grid);
                ans = min({ans, top+ middle+ bottom});
            }
        }
        return ans;
    }
    int minimumSum(vector<vector<int>>& grid) {
        int case1 = cases(grid);
        vector<vector<int>> rotatedgrid(grid[0].size(),
                                        vector<int>(grid.size()));
        for (int i = 0; i < rotatedgrid.size(); i++) {
            for (int j = 0; j < rotatedgrid[0].size(); j++) {
                rotatedgrid[i][j] = grid[grid.size() - 1 - j][i];
            }
        }
        int case2 = cases(rotatedgrid);
        return min(case1, case2);
    }
};
