//cpp
class Solution {
public:
    int m, n;
    typedef vector<int> vec;
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool safe(vector<vector<int>>& grid, int i, int j, int health) {
        vector<vec> result(m, vec(n, 0));
        priority_queue<vec, vector<vec>> pq;
        pq.push({health, i, j});
        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            int currhealth = temp[0];
            int x = temp[1];
            int y = temp[2];
            if (x == m - 1 && y == n - 1)
                return true;
            for (auto& d : dir) {
                int newx = d[0] + x;
                int newy = d[1] + y;
                if (newx >= 0 && newx < m && newy >= 0 && newy < n) {
                    int newhealth = currhealth - grid[newx][newy];
                    if (newhealth > result[newx][newy]) {
                        pq.push({newhealth, newx, newy});
                        result[newx][newy] = newhealth;
                    }
                }
            }
        }
        return result[m-1][n-1];
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m = grid.size();
        n = grid[0].size();
        return safe(grid, 0, 0, health - grid[0][0]);
    }
};
