//cpp
class Solution {
public:
    bool magicSquare(int row, int col, int k, vector<vector<int>>& grid) {
        int rowSum = -1;
        for (int i = row; i < row + k; i++) {
            int currRowSum = 0;
            for (int j = col; j < col + k; j++) {
                currRowSum += grid[i][j];
            }
            if (rowSum == -1)
                rowSum = currRowSum;
            else if (rowSum != currRowSum)
                return false;
        }
        for (int i = col; i < col + k; i++) {
            int colSum = 0;
            for (int j = row; j < row + k; j++) {
                colSum += grid[j][i];
            }
            if (colSum != rowSum)
                return false;
        }
        int diagonalSum1 = 0;
        int diagonalSum2 = 0;
        int i = row, j = col;
        while (i < row + k && j < col + k) {
            diagonalSum1 += grid[i][j];
            diagonalSum2 += grid[row + k - 1 - (i - row)][j];
            i++;
            j++;
        }
        return diagonalSum1 == diagonalSum2 && diagonalSum1 == rowSum;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxk = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 1; k <= min(m, n); k++) {
                    if (i + k <= m && j + k <= n) {
                        if (magicSquare(i, j, k, grid))
                            maxk = max(maxk, k);
                    }
                }
            }
        }
        return maxk;
    }
};
