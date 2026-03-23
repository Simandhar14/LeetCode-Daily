//cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int m, n;

    typedef pair<long long, long long> p; 

    p solve(vector<vector<int>>& grid, int i, int j, vector<vector<p>>& dp) {
    
        if (i == m - 1 && j == n - 1) {
            return {grid[i][j], grid[i][j]};
        }

     
        if (i >= m || j >= n) {
            return {LLONG_MIN, LLONG_MAX};
        }

       
        if (dp[i][j].first != LLONG_MIN)
            return dp[i][j];

        p right = solve(grid, i, j + 1, dp);
        p down  = solve(grid, i + 1, j, dp);

        long long val = grid[i][j];
        vector<long long> candidates;

        if (right.first != LLONG_MIN) {
            candidates.push_back(val * right.first);
            candidates.push_back(val * right.second);
        }

     
        if (down.first != LLONG_MIN) {
            candidates.push_back(val * down.first);
            candidates.push_back(val * down.second);
        }

        long long maxVal = *max_element(candidates.begin(), candidates.end());
        long long minVal = *min_element(candidates.begin(), candidates.end());

        return dp[i][j] = {maxVal, minVal};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<p>> dp(m, vector<p>(n, {LLONG_MIN, LLONG_MAX}));

        p result = solve(grid, 0, 0, dp);

        long long ans = result.first;

        if (ans < 0) return -1;

        return ans % MOD;
    }
};
