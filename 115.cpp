//cpp
class Solution {
public:
    vector<vector<int>> dp;
    int solve(string& s, string& t, int i, int j) {
        if (j == t.length())
            return 1;
        if (i == s.length())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int result = 0;
        if (s[i] == t[j]) {
            result += solve(s, t, i + 1, j + 1);
        }
        result += solve(s, t, i + 1, j);
        return dp[i][j] = result;
    }
    int numDistinct(string s, string t) {
        dp.assign(s.length(), vector<int>(t.length(), -1));
        return solve(s, t, 0, 0);
    }
};
