class Solution {
public:
    typedef pair<int, int> p;
    int n;
    const int MOD = 1e9 + 7;
    vector<vector<int>> dir = {{-1, 0}, {-1, -1}, {0, -1}};
    p solve(int row, int col, vector<string>& board, vector<vector<p>>& dp) {
        if (board[row][col] == 'E') {
            return {0, 1};
        }
        if (dp[row][col] != make_pair(-1, -1))
            return dp[row][col];
        p result = {-1, 0};
        for (auto& d : dir) {
            int newr = row + d[0];
            int newc = col + d[1];
            if (newr >= 0 && newc >= 0 && newr < n && newc < n &&
                board[newr][newc] != 'X') {
                p ans = solve(newr, newc, board, dp);
                if (ans == make_pair(-1, 0))
                    continue;
                if (ans.first > result.first) {
                    result.first = ans.first;
                    result.second = ans.second;
                } else if (ans.first == result.first)
                    result.second = (result.second + ans.second) % MOD;
            }
        }
        if (board[row][col] != 'S' && result.first != -1)
            result.first += board[row][col] - '0';
        return dp[row][col] = result;
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        vector<vector<p>> dp(n, vector<p>(n, {-1, -1}));
        int row = -1, col = -1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (board[i][j] == 'S') {
                    row = i;
                    col = j;
                    break;
                }
            }
        }
        p result = solve(row, col, board, dp);
        if (result.first == -1)
            return {0, 0};
        return {result.first, result.second % MOD};
    }
};
