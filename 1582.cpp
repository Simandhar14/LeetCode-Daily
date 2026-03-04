//cpp
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int>rowOnes(m,0);
        vector<int>colOnes(n,0);
        for(int i=0;i<m;i++)
        {
            int ones=0;
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1) ones++;
            }
            rowOnes[i]=ones;
        }

         for(int i=0;i<n;i++)
        {
            int ones=0;
            for(int j=0;j<m;j++)
            {
                if(mat[j][i]==1) ones++;
            }
            colOnes[i]=ones;
        }

        int specialPos=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1 && rowOnes[i]==1 && colOnes[j]==1) specialPos++;
            }
        }
        return specialPos;
    }
};
