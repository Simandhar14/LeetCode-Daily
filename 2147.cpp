class Solution {
public:
    int dp[3][100001];
    const int MOD = 1e9 + 7;
    int solve(string &corridor, int seats, int i) {
        if (i >= corridor.size()) {
            return (seats == 2);
        }
        if (dp[seats][i] != -1) return dp[seats][i];

        int newSeats = corridor[i] == 'S' ? seats + 1 : seats;
        if (newSeats > 2) return 0;

        int take = 0, skip = 0;
        if (newSeats == 2) {
            take = solve(corridor, 0, i + 1) % MOD;
        }
        skip = solve(corridor, newSeats, i + 1) % MOD;

        return dp[seats][i] = (take + skip) % MOD;
    }

    int numberOfWays(string corridor) {
        memset(dp, -1, sizeof(dp));
        return solve(corridor, 0, 0);
    }
};
