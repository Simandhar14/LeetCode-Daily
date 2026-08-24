//cpp
class Solution {
public:
    int n;
    vector<int> memo;

    int solve(int idx, vector<int>& prefixSum) {
        if (idx == n - 1) {
            return prefixSum[idx];
        }
        if (memo[idx] != -1e9) {
            return memo[idx];
        }
        int take = prefixSum[idx] - solve(idx + 1, prefixSum);

        int skip = solve(idx + 1, prefixSum);
        return memo[idx] = max(take, skip);
    }

    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        
        vector<int> prefixSum(n);
        prefixSum[0] = stones[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + stones[i];
        }
        memo.assign(n, -1e9);
        return solve(1, prefixSum);
    }
};
