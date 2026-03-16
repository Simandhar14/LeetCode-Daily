//cpp
class Solution {
public:
    int calculate(vector<vector<int>>& grid, int topi, int topj, int lefti,
                  int leftj, int righti, int rightj, int bottomi, int bottomj) {
        int sum = 0;
        int i = topi, j = topj;

        while (i != lefti || j != leftj) {
            sum += grid[i][j];
            i++;
            j--;
        }

        while (i != bottomi || j != bottomj) {
            sum += grid[i][j];
            i++;
            j++;
        }

        while (i != righti || j != rightj) {
            sum += grid[i][j];
            i--;
            j++;
        }

        while (i != topi || j != topj) {
            sum += grid[i][j];
            i--;
            j--;
        }

        return sum;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int sum1 = INT_MIN, sum2 = INT_MIN, sum3 = INT_MIN;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int size = 1; size < min(m, n); size++) {
                    int lefti = i + size;
                    int leftj = j - size;
                    if (leftj < 0 || lefti >= m)
                        break;

                    int righti = i + size;
                    int rightj = j + size;
                    if (righti >= m || rightj >= n)
                        break;

                    int bottomi = i + 2 * size;
                    int bottomj = j;

                    if (bottomi >= m)
                        break;
                    int sum = calculate(grid, i, j, lefti, leftj, righti,
                                        rightj, bottomi, bottomj);

                    if (sum == sum1 || sum == sum2 || sum == sum3)
                        continue;
                    if (sum > sum1) {
                        sum3 = sum2;
                        sum2 = sum1;
                        sum1 = sum;
                    } else if (sum > sum2) {
                        sum3 = sum2;
                        sum2 = sum;
                    } else if (sum > sum3)
                        sum3 = sum;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = grid[i][j];

                if (sum == sum1 || sum == sum2 || sum == sum3)
                    continue;
                if (sum > sum1) {
                    sum3 = sum2;
                    sum2 = sum1;
                    sum1 = sum;
                } else if (sum > sum2) {
                    sum3 = sum2;
                    sum2 = sum;
                } else if (sum > sum3)
                    sum3 = sum;
            }
        }
        vector<int> ans;
        if (sum1 != INT_MIN)
            ans.push_back(sum1);
        if (sum2 != INT_MIN)
            ans.push_back(sum2);
        if (sum3 != INT_MIN)
            ans.push_back(sum3);
        return ans;
    }
};
