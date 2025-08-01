class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>pascal(numRows);
        pascal[0].emplace_back(1);
        for(int i=1;i<numRows;i++)
        {
            int n=pascal[i-1].size();
            pascal[i].push_back(1);
            for(int j=0;j<n-1;j++)
            {
                pascal[i].emplace_back(pascal[i-1][j]+pascal[i-1][j+1]);
            }
            pascal[i].emplace_back(1);
        }
        return pascal;
    }
};
