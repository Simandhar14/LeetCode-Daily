class Solution {
public:
bool magicSquare(vector<vector<int>>& grid,int row,int col)
{
    unordered_set<int>st;
    int rowsum=-1;
    //check whether each rowsum is same and if grid has distinct numbers
    for(int i=row;i<row+3;i++) 
    {
        int sum=0;
        for(int j=col;j<col+3;j++)
        {
            sum+=grid[i][j];
            if(st.count(grid[i][j]) || grid[i][j]>9 || grid[i][j]<1) return false;
            st.insert(grid[i][j]);
        }
        if(rowsum==-1) rowsum=sum;
        else if(rowsum!=sum) return false;
    }
    //check whether sum of each column in the grid is same
    int colsum=-1;
     for(int i=col;i<col+3;i++) 
    {
        int sum=0;
        for(int j=row;j<row+3;j++)
        {
            sum+=grid[j][i];
        }
        if(colsum==-1) colsum=sum;
        else if(colsum!=sum) return false;
    }
    //check sum of diagonals is equal or not
    int diagonal1=grid[row][col]+grid[row+1][col+1]+grid[row+2][col+2];
    int diagonal2=grid[row+2][col]+grid[row+1][col+1]+grid[row][col+2];
    if(diagonal1!=diagonal2) return false;
    return true;
}
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<=m-3;i++)
        {
            for(int j=0;j<=n-3;j++){
                if(magicSquare(grid,i,j)) count++;
            }
        }
        return count;
    }
};
