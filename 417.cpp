//brute force
class Solution {
public:
    bool pacificFound = false;
    bool atlanticFound = false;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void solve(vector<vector<bool>>& visited, vector<vector<int>>& heights,
               int i, int j) {

        visited[i][j] = true;
        for (auto& dir : directions) {
            int newi = i + dir[0];
            int newj = j + dir[1];
            if (newi < 0 || newj < 0) {
                pacificFound = true;
            }
            else if (newi >= heights.size() || newj >= heights[0].size()) {
                atlanticFound = true;
            }
            
            if(pacificFound && atlanticFound) return;

            if (newi >= 0 && newi < heights.size() && newj >= 0 &&
                newj < heights[0].size() &&
                heights[newi][newj] <= heights[i][j] && !visited[newi][newj]) {
                solve(visited, heights, newi, newj);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<vector<bool>> visited(m, (vector<bool>(n, false)));
                solve(visited, heights, i, j);
                if (pacificFound && atlanticFound) {
                    ans.push_back({i, j});
                }
                pacificFound = false;
                atlanticFound = false;
            }
        }
        return ans;
    }
};

//optimised brute force
class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    void solve(vector<vector<int>>& heights, vector<vector<int>>& visited,
               int i, int j, bool &pacificFound, bool &atlanticFound, int visitId) {
        if (visited[i][j] == visitId || (pacificFound && atlanticFound)) return;
        visited[i][j] = visitId;

        for (auto &dir : directions) {
            int newi = i + dir[0];
            int newj = j + dir[1];

            if (newi < 0 || newj < 0) { pacificFound = true; continue; }
            if (newi >= heights.size() || newj >= heights[0].size()) { atlanticFound = true; continue; }

            if (heights[newi][newj] <= heights[i][j])
                solve(heights, visited, newi, newj, pacificFound, atlanticFound, visitId);

            if (pacificFound && atlanticFound) return;
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int visitId = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bool pacificFound = false, atlanticFound = false;
                ++visitId;
                solve(heights, visited, i, j, pacificFound, atlanticFound, visitId);
                if (pacificFound && atlanticFound)
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};


//better approach
class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void solve(vector<vector<int>>& heights, vector<vector<bool>>& visited,
               int i, int j) {
        visited[i][j] = true;
        for (auto& dir : directions) {
            int newi = i + dir[0];
            int newj = j + dir[1];
            if (newi >= 0 && newj >= 0 && newi < heights.size() &&
                newj < heights[0].size() &&
                heights[newi][newj] >= heights[i][j] && !visited[newi][newj])
                solve(heights, visited, newi, newj);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            solve(heights, pacific, i, 0); //pacific left
            solve(heights, atlantic, i, n - 1); //atlantic right
        }
        for (int j = 0; j < n; j++) {
            solve(heights, pacific, 0, j); //pacific top
            solve(heights, atlantic, m - 1, j); //atlantic bottom
        }
        vector<vector<int>>ans;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
