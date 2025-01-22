class Solution {
public:
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> result(m, vector<int>(n, -1));
        queue<pair<int, int>> que;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    que.push({i, j});
                    result[i][j] = 0;
                }
            }
        }
        while (!que.empty()) {
            auto temp = que.front();
            que.pop();
            int i = temp.first;
            int j = temp.second;
            int val=result[i][j];
            for(auto dir:directions)
            {
                int newi=i+dir[0];
                int newj=j+dir[1];
                if(newi<m && newi>=0 && newj<n && newj>=0 && result[newi][newj]==-1)
                {
                    result[newi][newj]=val+1;
                    que.push({newi,newj});
                }
            }
        }
        return result;
    }
};