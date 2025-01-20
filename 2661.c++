class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<pair<int,int>>vec((m*n)+1);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                vec[mat[i][j]]={i,j};
            }
        }
        vector<int>row(m,0);
        vector<int>col(n,0);
        for(int idx=0;idx<m*n;idx++)
        {
           auto temp=vec[arr[idx]];
           int i=temp.first;
           int j=temp.second;
           row[i]++;
           col[j]++;
           if(row[i]==n || col[j]==m) return idx;
        }
        return -1;
    }
};