class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        bool lefttoright = true;
        int m = mat.size();
        int n = mat[0].size();
        vector<int> diagonal;
        int row = 0;
        int col = 0;
        int k = 0;
        for (int k = 0; k < m * n; k++) {
            int i = row;
            int j = col;
            if (lefttoright) {
                diagonal.emplace_back(mat[i][j]);
                if (i == 0) {
                    if (j != n - 1) {
                        row = 0;
                        col = j + 1;
                    } else {
                        row = i + 1;
                        col = n - 1;
                    }
                    lefttoright = !lefttoright;
                } else if (j == n - 1) {
                    row = i + 1;
                    col = j;
                     lefttoright = !lefttoright;
                } else {
                    i--;
                    j++;
                    row = i;
                    col = j;
                }
            } else {
                diagonal.emplace_back(mat[i][j]);
                if (i == m - 1) {
                    if (j != n - 1) {
                        row = m - 1;
                        col = j + 1;
                    }
                    lefttoright = !lefttoright;
                } else if (j == 0) {
                    col = 0;
                    row = i + 1;
                    lefttoright = !lefttoright;
                } else {
                    i++;
                    j--;
                    row = i;
                    col = j;
                }
            }
        }
        return diagonal;
    }
};
