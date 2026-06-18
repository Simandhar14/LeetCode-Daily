//cpp
class Solution {
public:
    int number = 1;
    void solve(int topR, int bottomR, int leftC, int rightC,
               vector<vector<int>>& grid) {
        for (int col = leftC; col <= rightC; col++) {
            grid[topR][col] = number;
            number++;
        }
        for (int row = topR + 1; row <= bottomR; row++) {
            grid[row][rightC] = number;
            number++;
        }
        for (int col = rightC - 1; col >= leftC; col--) {
            grid[bottomR][col] = number;
            number++;
        }
        for (int row = bottomR - 1; row > topR; row--) {
            grid[row][leftC] = number;
            number++;
        }
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> grid(n, vector<int>(n));
        int topR = 0, bottomR = n - 1, leftC = 0, rightC = n - 1;
        while (topR <= bottomR && leftC <= rightC) {
            solve(topR, bottomR, leftC, rightC, grid);
            topR++, bottomR--, leftC++, rightC--;
        }
        return grid;
    }
};
