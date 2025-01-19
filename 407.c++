class Solution {
public:
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    typedef pair<int, pair<int, int>> PP;
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        priority_queue<PP, vector<PP>, greater<PP>> pq;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int trapwater = 0;
        pq.push({0,{0,0}});
        visited[0][0]=1;
        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            int height = temp.first;
            int i = temp.second.first;
            int j = temp.second.second;
            for (auto dir : directions) {
                int new_i = i + dir[0];
                int new_j = j + dir[1];
                if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n &&
                    !visited[new_i][new_j]) {
                    visited[new_i][new_j] = 1;
                    trapwater += max(height - heightMap[new_i][new_j], 0);
                    int maxval = max(heightMap[i][j], heightMap[new_i][new_j]);
                    pq.push({maxval, {new_i, new_j}});
                }
            }
        }
        return trapwater;
    }
};