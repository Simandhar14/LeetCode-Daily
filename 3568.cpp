//cpp
class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    struct state {
        int row;
        int col;
        int energy;
        int litter;
    };
    int bfs(vector<string>& classroom, int maxenergy, int litterCount,
            int startrow, int startcol, vector<vector<int>>& bitposition) {
        queue<state> que;
        vector<vector<vector<vector<int>>>> visited(
            m, vector<vector<vector<int>>>(
                   n, vector<vector<int>>(maxenergy + 1,
                                          vector<int>(1 << litterCount, 0))));
        que.push({startrow, startcol, maxenergy, 0});
        visited[startrow][startcol][maxenergy][0] = true;
        int steps = 0;
        int finish = (1 << litterCount) - 1;
        while (!que.empty()) {
            int len = que.size();
            while (len--) {
                state temp = que.front();
                que.pop();
                if (temp.litter == finish)
                    return steps;
                if (temp.energy == 0)
                    continue;
                for (auto& d : directions) {
                    int newi = temp.row + d[0];
                    int newj = temp.col + d[1];
                    if (newi < 0 || newj < 0 || newi >= m || newj >= n)
                        continue;
                    if (classroom[newi][newj] == 'X')
                        continue;
                    int newenergy = temp.energy - 1;
                    int newlitter = temp.litter;
                    if (classroom[newi][newj] == 'R')
                        newenergy = maxenergy;
                    if (classroom[newi][newj] == 'L')
                        newlitter =
                            temp.litter | (1 << (bitposition[newi][newj]));
                    if (!visited[newi][newj][newenergy][newlitter]) {
                        visited[newi][newj][newenergy][newlitter] = 1;
                        que.push({newi, newj, newenergy, newlitter});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
    int minMoves(vector<string>& classroom, int energy) {
        m = classroom.size();
        n = classroom[0].size();
        int startrow = -1, startcol = -1, litterCount = 0, bitpos = 0;
        vector<vector<int>> bitposition(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    startrow = i;
                    startcol = j;
                }
                if (classroom[i][j] == 'L') {
                    litterCount++;
                    bitposition[i][j] = bitpos;
                    bitpos++;
                }
            }
        }
        if (litterCount == 0)
            return 0;
        return bfs(classroom, energy, litterCount, startrow, startcol,
                   bitposition);
    }
};
