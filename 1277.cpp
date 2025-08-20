//using dp
class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& matrix, int i, int j) {
        if (i >= m || j >= n || i < 0 || j < 0 || matrix[i][j] == 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int down = solve(matrix, i + 1, j);
        int diag = solve(matrix, i + 1, j + 1);
        int right = solve(matrix, i, j + 1);
        return dp[i][j] = 1 + min({down, diag, right});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int totalSquare = 0;
        m = matrix.size();
        n = matrix[0].size();
        dp.resize(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0)
                    continue;
                totalSquare += solve(matrix, i, j);
            }
        }
        return totalSquare;
    }
};

//brute force
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int countSquare=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==1) countSquare++;
                if(matrix[i][j]==0) continue;
                int newi=i+1;
                int newj=j+1;
                while(newi<m && newj<n)
                {
                    bool check;
                    for(int i2=i;i2<=newi;i2++)
                    {
                        check=true;
                        for(int j2=j;j2<=newj;j2++)
                        {
                            if(matrix[i2][j2]==0)
                            {
                                check=false;
                                break;
                            }
                        }
                        if(check==false) break;
                    }
                    if(check==true) countSquare++;
                    newi++;
                    newj++;
                }
            }
        }
        return countSquare;
    }
};
