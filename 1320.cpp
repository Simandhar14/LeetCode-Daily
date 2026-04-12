//cpp
class Solution {
public:
    int solve(string& word, char finger1, char finger2, int i,
              vector<vector<vector<int>>>& dp) {
        if (i >= word.length())
            return 0;

        int f1 = (finger1 == '$') ? 26 : finger1 - 'A';
        int f2 = (finger2 == '$') ? 26 : finger2 - 'A';

        if (dp[f1][f2][i] != INT_MAX)
            return dp[f1][f2][i];

        char current = word[i];
        int curr = current - 'A';

        int ans = INT_MAX;

        // use finger1
        if (finger1 == '$') {
            ans = min(ans, solve(word, current, finger2, i + 1, dp));
        } else {
            int x1 = curr / 6, y1 = curr % 6;
            int x2 = f1 / 6, y2 = f1 % 6;
            int dist = abs(x1 - x2) + abs(y1 - y2);
            ans = min(ans, dist + solve(word, current, finger2, i + 1, dp));
        }

        // use finger2
        if (finger2 == '$') {
            ans = min(ans, solve(word, finger1, current, i + 1, dp));
        } else {
            int x1 = curr / 6, y1 = curr % 6;
            int x2 = f2 / 6, y2 = f2 % 6;
            int dist = abs(x1 - x2) + abs(y1 - y2);
            ans = min(ans, dist + solve(word, finger1, current, i + 1, dp));
        }

        return dp[f1][f2][i] = ans;
    }

    int minimumDistance(string word) {
        int n = word.length();
        vector<vector<vector<int>>> dp(
            27, vector<vector<int>>(27, vector<int>(n, INT_MAX)));

        return solve(word, '$', '$', 0, dp);
    }
};
