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

//recursion

class Solution {
public:
void solve(vector<int>&diagonal,int m,int n,int i,int j,int count,bool up,vector<vector<int>>& mat)
{
    if(count==0) return;
    diagonal.emplace_back(mat[i][j]);
    if(up)
    {
        if(j==n-1)
        {
            solve(diagonal,m,n,i+1,j,count-1,!up,mat);
        }else if(i==0){
            solve(diagonal,m,n,i,j+1,count-1,!up,mat);
        }else{
            solve(diagonal,m,n,i-1,j+1,count-1,up,mat);
        }
    }else{
        if(i==m-1)
        {
            solve(diagonal,m,n,i,j+1,count-1,!up,mat);
        }else if(j==0){
            solve(diagonal,m,n,i+1,j,count-1,!up,mat);
        }else{
            solve(diagonal,m,n,i+1,j-1,count-1,up,mat);
        }
    }
}
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        bool lefttoright = true;
        int m = mat.size();
        int n = mat[0].size();
        vector<int> diagonal;
        int row = 0;
        int col = 0;
        solve(diagonal,m,n,0,0,m*n,lefttoright,mat);
        return diagonal;
    }
};
