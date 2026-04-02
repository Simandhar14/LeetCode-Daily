//top down 
class Solution {
public:
    int dp[501][501][3];
    int maxMoney(int i, int j, int neutralize, vector<vector<int>>& coins) {
        if (i == 0 && j == 0) {
            if (coins[i][j] <= 0 && neutralize > 0)
                return 0;
            return coins[i][j];
        }
        if (i < 0 || j < 0)
            return INT_MIN;
        if (dp[i][j][neutralize] != -1e9)
            return dp[i][j][neutralize];
        int left, up;
        int result = INT_MIN;
        if (coins[i][j] <= 0) {
            if (neutralize > 0) {
                left = maxMoney(i, j - 1, neutralize - 1, coins);
                up = maxMoney(i - 1, j, neutralize - 1, coins);
                if (left != INT_MIN)
                    result = max(result, left);
                if (up != INT_MIN)
                    result = max(result, up);
            }
        }
        left = maxMoney(i, j - 1, neutralize, coins); // skip neutralize
        up = maxMoney(i - 1, j, neutralize, coins);
        if (left != INT_MIN)
            result = max(result, coins[i][j] + left);
        if (up != INT_MIN)
            result = max(result, coins[i][j] + up);
        return dp[i][j][neutralize] = result;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        for (int i = 0; i < 501; i++) {
            for (int j = 0; j < 501; j++) {
                for (int k = 0; k < 3; k++) {
                    dp[i][j][k] = -1e9;
                }
            }
        }
        return maxMoney(m - 1, n - 1, 2, coins);
    }
};

//bottom up
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        int dp[m][n][3];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int neutralize = 0; neutralize < 3; neutralize++) {
                    if (i == 0 && j == 0) {
                        if (coins[0][0] < 0 && neutralize > 0) {
                            dp[0][0][neutralize] = 0;
                        } else
                            dp[0][0][neutralize] = coins[i][j];
                        continue;
                    }
                    int left = INT_MIN, up = INT_MIN;
                    int result = INT_MIN;
                    if (coins[i][j] < 0) {
                        if (neutralize > 0) {
                            if (j - 1 >= 0)
                                left = dp[i][j - 1][neutralize - 1];
                            if (i - 1 >= 0)
                                up = dp[i - 1][j][neutralize - 1];
                            if (left != INT_MIN)
                                result = max(result, left);
                            if (up != INT_MIN)
                                result = max(result, up);
                        }
                    }
                    if (j - 1 >= 0)
                        left = dp[i][j - 1][neutralize]; // skip neutralize
                    if (i - 1 >= 0)
                        up = dp[i - 1][j][neutralize];
                    if (left != INT_MIN)
                        result = max(result, coins[i][j] + left);
                    if (up != INT_MIN)
                        result = max(result, coins[i][j] + up);
                    dp[i][j][neutralize] = result;
                }
            }
        }
        int ans = INT_MIN;
        for (int neutralize = 0; neutralize < 3; neutralize++) {
            ans = max(ans, dp[m - 1][n - 1][neutralize]);
        }
        return ans;
    }
};
