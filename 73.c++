class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>index;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0) index.push_back({i,j});
            }
        }
        for(auto temp:index)
        {
            int i=temp.first;
            int j=temp.second;
            for(int col=0;col<n;col++)
            {
                matrix[i][col]=0;
            }
             for(int row=0;row<m;row++)
            {
                matrix[row][j]=0;
            }
        }
    }
};
