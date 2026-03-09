//cpp
class Solution {
public:
    int mod = 1e9 + 7;
    int dp[201][201][2][201];

    int solve(int zero, int one, int limit, int last, int cons) {
        if (zero == 0 && one == 0)
            return 1;

        if (dp[zero][one][last][cons] != -1)
            return dp[zero][one][last][cons];

        long long ans = 0;

        if (zero > 0) {
            if (last != 0)
                ans += solve(zero - 1, one, limit, 0, 1);
            else if (cons < limit)
                ans += solve(zero - 1, one, limit, 0, cons + 1);
        }

        if (one > 0) {
            if (last != 1)
                ans += solve(zero, one - 1, limit, 1, 1);
            else if (cons < limit)
                ans += solve(zero, one - 1, limit, 1, cons + 1);
        }

        ans %= mod;          

        return   dp[zero][one][last][cons] = ans;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp, -1, sizeof(dp));

        long long ans = 0;

        if (zero > 0)
            ans += solve(zero - 1, one, limit, 0, 1);

        if (one > 0)
            ans += solve(zero, one - 1, limit, 1, 1);

        return ans % mod;
    }
};
