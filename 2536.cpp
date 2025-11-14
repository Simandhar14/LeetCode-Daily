class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n, vector<int>(n, 0));
        for (auto& temp : queries) {
            int r1 = temp[0];
            int r2 = temp[2];
            int c1 = temp[1];
            int c2 = temp[3];
            for(int i=r1;i<=r2;i++)
            {
                diff[i][c1]++;
                if(c2+1<n)
                {
                    diff[i][c2+1]-=1;
                }
            }
          
        }
        for (int i = 0; i < n; i++) {
            int sum=0;
            for (int j = 0; j < n; j++) {
               sum+=diff[i][j];
               diff[i][j]=sum;
            }
        }
        return diff;
    }
};
