class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int rectangle = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0)
                    continue;
                int count = 0;
                int x = i, y = j + 1;
                int downidx=x;
                while (x < m && mat[x][j] == 1) {
                    count++;
                    x++;
                }
                int downidx=x-1;
                while (y < n && mat[i][y] == 1) {
                    x = i;
                    while (x <= downidx) {
                        if (mat[x][y] == 1) {
                            count++;
                            x++;
                        } else {
                            downidx = x - 1;
                            break;
                        }
                    }
                    y++;
                }
                rectangle += count;
            }
        }
        return rectangle;
    }
};
