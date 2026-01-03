//dp + memo
class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[5001][13];

    int solve(vector<string>& states, int rows, int index) {
        if (rows == 0)
            return 1;

        if (dp[rows][index + 1] != -1)
            return dp[rows][index + 1];

        int result = 0;

        for (int i = 0; i < 12; i++) {
            if (i == index)
                continue;

            if (index == -1 || (states[index][0] != states[i][0] &&
                                states[index][1] != states[i][1] &&
                                states[index][2] != states[i][2])) {
                result = (result + solve(states, rows - 1, i)) % MOD;
            }
        }

        return dp[rows][index + 1] = result;
    }

    int numOfWays(int n) {
        vector<string> states = {"RGB", "RBG", "BRG", "BGR", "GRB", "GBR",
                                 "RGR", "GRG", "BRB", "BGB", "RBR", "GBG"};

        memset(dp, -1, sizeof(dp));
        return solve(states, n, -1);
    }
};
