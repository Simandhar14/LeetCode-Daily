//recursion
class Solution {
public:
int m,n;
    vector<vector<int>> dir{{1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    int solve(int i, int j, vector<vector<int>>& grid, int expected, int turn,
              int diag) {
        if (i < 0 || j < 0 || j >= n || i >= m)
            return 0;
        if(expected!=1 && grid[i][j]!=expected) return 0;
        int newexpected= expected==1 ? 2 : 2-expected;
        int taketurn = 0;
        int noturn = 1 + solve(i + dir[diag][0], j + dir[diag][1], grid,
                              newexpected, turn, diag);
        if (turn) {
            if (diag == 0) {
                taketurn = 1 + solve(i + dir[2][0], j + dir[2][1], grid,
                                    newexpected, turn - 1, 2);
            } else if (diag == 2) {
                taketurn = 1 + solve(i + dir[1][0], j + dir[1][1], grid,
                                    newexpected, turn - 1, 1);
            } else if (diag == 1) {
                taketurn = 1 + solve(i + dir[3][0], j + dir[3][1], grid,
                                    newexpected, turn - 1, 3);
            } else if (diag == 3) {
                taketurn = 1 + solve(i + dir[0][0], j + dir[0][1], grid,
                                    newexpected, turn - 1, 0);
            }
        }
        return max(taketurn, noturn);
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int result1 = solve(i, j, grid, 1, 1, 0);
                    int result2 = solve(i, j, grid, 1, 1, 1);
                    int result3 = solve(i, j, grid, 1, 1, 2);
                    int result4 = solve(i, j, grid, 1, 1, 3);
                    ans = max({ans,result1,result2,result3,result4});
                }
            }
        }
        return ans;
    }
};
